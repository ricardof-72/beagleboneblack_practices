#include "soc_AM335x.h"
#include "timer.h"

#define TIMER_1US_COUNT 24000000

static unsigned int DMTimerWritedPostedStatusGet() {
    /* Retorna o status do registrador TWPS */
    return (HWREG(DMTIMER7_TWPS));
}

#define DMTimerWaitForWrite(reg) \
    if(HWREG(DMTIMER7_TSICR) & (1 << 2)) \
    while((reg & DMTimerWritedPostedStatusGet()));

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

void uDelay(unsigned int us) {
    // Calcula o total de ticks necessarios
    unsigned int ticks_needed = us * TIMER_1US_COUNT;
    
    DMTimerCounterSet(0);
    DMTimerEnable();
    while(DMTimerCounterGet() < ticks_needed);
    DMTimerDisable();
}
