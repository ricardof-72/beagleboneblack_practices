#include "system_init.h"

#include "soc_AM335x.h"
#define CM_PER_GPIO1_CLKCTRL 0xAC
#define GPIO_MODE_VALUE 0x7

void SystemInit() {
    HWREG(SOC_CM_PER_REGS + CM_PER_GPIO1_CLKCTRL) |= MODULEMODE; // ativação do clock do gpio utilizado

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
}