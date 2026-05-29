#include "soc_AM335x.h"

#define CM_PER_GPIO1_CLKCTRL 0xAC
#define MODULE_MODE 0x2
#define GPIO_MODE_VALUE 0x7

int main() {
    HWREG(SOC_CM_PER_REGS + CM_PER_GPIO1_CLKCTRL) |= MODULE_MODE; // ativação do clock do gpio utilizado

    /* multiplexação do pino */
    HWREG(SOC_CONTROL_CONF_GPMC_A5) |= GPIO_MODE_VALUE;
    HWREG(SOC_CONTROL_CONF_GPMC_BEN1) |= GPIO_MODE_VALUE;

    /* definindo o gpio21 como saida */
    HWREG(SOC_GPIO_1_OE) &= ~(1 << 21);
    HWREG(SOC_GPIO_1_OE) &= ~(1 << 22);
    HWREG(SOC_GPIO_1_OE) &= ~(1 << 23);
    HWREG(SOC_GPIO_1_OE) &= ~(1 << 24);

    /* led externo */
    HWREG(SOC_GPIO_1_OE) &= ~(1 << 28);
    
    /* loop para piscar os leds, internos e o externo, em uma sequência específica */
    while(1){
        HWREG(SOC_GPIO_1_SETDATAOUT) |= (1 << 21);
        for (volatile unsigned int time = 0; time < 10000000; time++);
        HWREG(SOC_GPIO_1_CLEARDATAOUT) |= (1 << 21);

        HWREG(SOC_GPIO_1_SETDATAOUT) |= (1 << 24);
        for (volatile unsigned int time = 0; time < 10000000; time++);
        HWREG(SOC_GPIO_1_CLEARDATAOUT) |= (1 << 24);

        HWREG(SOC_GPIO_1_SETDATAOUT) |= (1 << 22);
        for (volatile unsigned int time = 0; time < 10000000; time++);
        HWREG(SOC_GPIO_1_CLEARDATAOUT) |= (1 << 22);

        HWREG(SOC_GPIO_1_SETDATAOUT) |= (1 << 23);
        for (volatile unsigned int time = 0; time < 10000000; time++);
        HWREG(SOC_GPIO_1_CLEARDATAOUT) |= (1 << 23);
        
        HWREG(SOC_GPIO_1_SETDATAOUT) |= (1 << 28);
        for (volatile unsigned int time = 0; time < 10000000; time++);
        HWREG(SOC_GPIO_1_CLEARDATAOUT) |= (1 << 28);

        HWREG(SOC_GPIO_1_SETDATAOUT) |= (1 << 23);
        for (volatile unsigned int time = 0; time < 10000000; time++);
        HWREG(SOC_GPIO_1_CLEARDATAOUT) |= (1 << 23);

        HWREG(SOC_GPIO_1_SETDATAOUT) |= (1 << 22);
        for (volatile unsigned int time = 0; time < 10000000; time++);
        HWREG(SOC_GPIO_1_CLEARDATAOUT) |= (1 << 22);

        HWREG(SOC_GPIO_1_SETDATAOUT) |= (1 << 24);
        for (volatile unsigned int time = 0; time < 10000000; time++);
        HWREG(SOC_GPIO_1_CLEARDATAOUT) |= (1 << 24);

        HWREG(SOC_GPIO_1_SETDATAOUT) |= (1 << 21);
        for (volatile unsigned int time = 0; time < 10000000; time++);
        HWREG(SOC_GPIO_1_CLEARDATAOUT) |= (1 << 21);
    }    
}

