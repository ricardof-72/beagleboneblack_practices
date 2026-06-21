#include "system_init.h"
#include "soc_AM335x.h"

#define GPIO_MODE_VALUE 0x37

void SystemInit() {
    /* desativando o watchdog */
    HWREG(SOC_WDT_1_WSPR) = 0xAAAA;
    while(HWREG(SOC_WDT_1_WWPS) & (1 << 4));
    HWREG(SOC_WDT_1_WSPR) = 0x5555;
    while(HWREG(SOC_WDT_1_WWPS) & (1 << 4));
    
    /* ativação do clock do gpio1 */
    HWREG(SOC_CM_PER_GPIO1_CLKCTRL) |= MODULEMODE; 

    /* ativação do clock do timer */
    HWREG(SOC_CM_PER_TIMER7_CLKCTRL) |= MODULEMODE;

    /* multiplexação do botão que será utilizado */
    HWREG(SOC_CONTROL_CONF_GPMC_AD12) |= GPIO_MODE_VALUE;
    HWREG(SOC_CONTROL_CONF_GPMC_AD14) |= GPIO_MODE_VALUE;
    HWREG(SOC_CONTROL_CONF_GPMC_AD13) |= GPIO_MODE_VALUE;
    HWREG(SOC_CONTROL_CONF_GPMC_AD15) |= GPIO_MODE_VALUE;
    HWREG(SOC_CONTROL_CONF_GPMC_CSN0) |= GPIO_MODE_VALUE;

    /* Definindo os pinos dos LEDs externos como saida */
    HWREG(SOC_GPIO_1_OE) &= ~(1 << 13);
    HWREG(SOC_GPIO_1_OE) &= ~(1 << 15);
    HWREG(SOC_GPIO_1_OE) &= ~(1 << 29);

    /* definindo o pino dos botões (bit 12 e 14) como entrada */
    HWREG(SOC_GPIO_1_OE) |= (1 << 12);
    HWREG(SOC_GPIO_1_OE) |= (1 << 14);

    /* garantindo que todos os leds comecem completamente apagados antes do loop */
    HWREG(SOC_GPIO_1_CLEARDATAOUT) = (1 << 13) | (1 << 15) | (1 << 29);
}