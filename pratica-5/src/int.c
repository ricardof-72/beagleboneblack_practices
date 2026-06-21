#include "soc_AM335x.h"
#include "int.h"
#include "stdbool.h"

#define SoftReset               0x0
#define ResetDone               0x1
#define PriorityThreshold       0x5
#define SYS_INT_GPIOINT1A       98
#define SYS_INT_TINT7           95
volatile bool FlagGPIO;
volatile bool FlagGPIO2;
volatile bool FlagTimer;

void IntAINTCInit() {
    /* reseta o controlador de interrupção */
    HWREG(SOC_AINTC_SYSCONFIG) = SoftReset; 

    /* espera o reset ser completo */
    while((HWREG(SOC_AINTC_SYSSTATUS) & ResetDone) != ResetDone);

    /* ativa a geração de qualquer interrupção setando o limite de prioridade */
    HWREG(SOC_AINTC_THRESHOLD) = PriorityThreshold;

    /* máscara de interrupção */
    HWREG(SOC_AINTC_MIR_CLEAR2) = (1 << 31);            // DMTIMER7
    HWREG(SOC_AINTC_MIR_CLEAR3) = (1 << 2);             // GPIO 1
 
    /* setando o pino de interrupção do gpio */
    HWREG(SOC_GPIO_1_IRQSTATUS_SET_0) |= (1 << 12);     // GPIO1_12
    HWREG(SOC_GPIO_1_IRQSTATUS_SET_0) |= (1 << 14);     // GPIO1_14

    /* ativando a geração da interrupção para detectar a borda de descida */
    HWREG(SOC_GPIO_1_FALLINGDETECT) |= (1 << 12);
    HWREG(SOC_GPIO_1_FALLINGDETECT) |= (1 << 14);
}

void gpioIsr() {
    unsigned int status = HWREG(SOC_GPIO_1_IRQSTATUS_0);
    if(status & (1 << 12)){
        FlagGPIO = false;
        HWREG(SOC_GPIO_1_IRQSTATUS_0) = (1 << 12);
    }

    if(status & (1 << 14)){
        FlagGPIO2 = false;
        HWREG(SOC_GPIO_1_IRQSTATUS_0) = (1 << 14);
    }
}

void DMTimerIsr() {
    FlagTimer = true;
    HWREG(DMTIMER7_IRQSTATUS) = 0x2;
}

void ISRHandler() {
    unsigned int intrNum;

    intrNum = HWREG(SOC_AINTC_SIR_IRQ) & 0x7F;
    switch (intrNum) {
        case SYS_INT_TINT7:
            DMTimerIsr();
            break;
        case SYS_INT_GPIOINT1A:
            gpioIsr();
            break;
        default:
            break;
    } /* fim do switch */

    HWREG(SOC_AINTC_INTC_CONTROL) = 0x1;
}