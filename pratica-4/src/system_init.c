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

    /* ativacao do clock para o timer7 */ 
    HWREG(SOC_CM_PER_TIMER7_CLKCTRL) |= MODULEMODE;
    /* primeiro le o valor do CLKCTRL e faz uma operacao para isolar apenas os dois ultimos bits,
       depois compara o resultado com o MODULEMODE. Enquanto o valor lido nao for igual a 0x2, o
       codigo fica preso no while */
    while((HWREG(SOC_CM_PER_TIMER7_CLKCTRL) & 0x3) != MODULEMODE);

    /* multiplexação do pino */
    HWREG(SOC_CONTROL_CONF_GPMC_BEN1) |= GPIO_MODE_VALUE;

    // O bit 2 ativa o posted mode do TSICR, para melhorar a latencia de escrita
    HWREG(DMTIMER7_TSICR) |= (1 << 2);

    // Confirma que o timer esta parado antes da configuracao
    while(HWREG(DMTIMER7_TWPS) & (1 << 0));
    HWREG(DMTIMER7_TCLR) &= ~(1 << 0);

    //Reseta o counter register e o load register
    while(HWREG(DMTIMER7_TWPS) & (1 << 1));

    HWREG(DMTIMER7_TCRR) = 0x00000000;
    HWREG(DMTIMER7_TLDR) = 0x00000000;

    /* led externo */
    HWREG(SOC_GPIO_1_OE) &= ~(1 << 28);
}
