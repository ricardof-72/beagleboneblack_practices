#include "system_init.h"

#include "soc_AM335x.h"
#define GPIO_MODE_VALUE 0x17

void SystemInit() {
    /* desativando o watchdog */
    HWREG(SOC_WDT_1_WSPR) = 0xAAAA;
    while(HWREG(SOC_WDT_1_WWPS) & (1 << 4));
    HWREG(SOC_WDT_1_WSPR) = 0x5555;
    while(HWREG(SOC_WDT_1_WWPS) & (1 << 4));
    
    /* ativação do clock do gpio1 */
    HWREG(SOC_CM_PER_GPIO1_CLKCTRL) |= MODULEMODE; 

    /* multiplexação dos botões que serão utilizados */
    HWREG(SOC_CONTROL_CONF_GPMC_BEN1) |= GPIO_MODE_VALUE;
    HWREG(SOC_CONTROL_CONF_GPMC_CSN0) |= GPIO_MODE_VALUE;

    /* Definindo os pinos dos LEDs internos (21 a 24) como saida */
    HWREG(SOC_GPIO_1_OE) &= ~(1 << 21);
    HWREG(SOC_GPIO_1_OE) &= ~(1 << 22);
    HWREG(SOC_GPIO_1_OE) &= ~(1 << 23);
    HWREG(SOC_GPIO_1_OE) &= ~(1 << 24);

    /* definindo o pino do botão (bit 28) como entrada */
    HWREG(SOC_GPIO_1_OE) |= (1 << 28);
    HWREG(SOC_GPIO_1_OE) |= (1 << 29);

    /* garantindo que todos os leds comecem completamente apagados antes do loop */
    HWREG(SOC_GPIO_1_CLEARDATAOUT) = (1 << 21) | (1 << 22) | (1 << 23) | (1 << 24);
}