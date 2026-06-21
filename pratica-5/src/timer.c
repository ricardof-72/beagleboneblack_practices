#include "soc_AM335x.h"
#include "timer.h"
#include "int.h"

#define TIMER_1MS_COUNT 24000000
#define TIMER_OVERFLOW 0xFFFFFFFF
extern volatile bool FlagTimer;

unsigned int DMTimerWritedPostedStatusGet() {
    /* Retorna o status do registrador TWPS */
    return (HWREG(DMTIMER7_TWPS));
}

void DMTimerCounterSet(unsigned int counter) {
    // Espera a escrita anterior terminar
    DMTimerWaitForWrite(1 << 1);

    // Seta o valor do contador
    HWREG(DMTIMER7_TCRR) = counter;
}

unsigned int DMTimerCounterGet() {
    // Espera a escrita anterior terminar
    DMTimerWaitForWrite(1 << 1);

    // Le o valor do contador do TCRR
    return (HWREG(DMTIMER7_TCRR));
}

void DMTimerEnable() {
    // Espera a escrita anterior terminar
    DMTimerWaitForWrite(1 << 0);

    // Inicia o timer
    HWREG(DMTIMER7_TCLR) |= (1 << 0);
}

void DMTimerDisable() {
    // Espera a escrita anterior terminar
    DMTimerWaitForWrite(1 << 0);

    // Para o timer
    HWREG(DMTIMER7_TCLR) &= ~(1 << 0);
}

void delay(unsigned int mSec) {
    unsigned int countVal = TIMER_OVERFLOW - (mSec * TIMER_1MS_COUNT);
    
    /* desativa o modo posted */
    HWREG(DMTIMER7_TSICR) &= ~(1 << 2);

    FlagTimer = false;

    /* carrega o registrador com o valor calculado */
    HWREG(DMTIMER7_TCRR) = countVal;

    /* ativa a interrupção do DMTIMER */
    HWREG(DMTIMER7_IRQENABLE_SET) = 0x2;

    /* liga o cronômetro */
    HWREG(DMTIMER7_TCLR) |= (1 << 0);

    while(FlagTimer == false){};

    /* desativa o cronômetro */
    HWREG(DMTIMER7_TCLR) &= ~(1 << 0);

    /* desativa a interrupção do DMTIMER */
    HWREG(DMTIMER7_IRQENABLE_CLR) = 0x2;
}
