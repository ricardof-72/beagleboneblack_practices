#include "func_buttons.h"
#include "int.h"

#include "soc_AM335x.h"

void RPressedButton() {
    /* botão da direita pressionado */
    HWREG(SOC_GPIO_1_SETDATAOUT) = (1 << 13);
    delay(2);
    HWREG(SOC_GPIO_1_CLEARDATAOUT) = (1 << 13);
    delay(2);

    HWREG(SOC_GPIO_1_SETDATAOUT) = (1 << 15);
    delay(2);
    HWREG(SOC_GPIO_1_CLEARDATAOUT) = (1 << 15);
    delay(2);

    HWREG(SOC_GPIO_1_SETDATAOUT) = (1 << 29);
    delay(2);
    HWREG(SOC_GPIO_1_CLEARDATAOUT) = (1 << 29);
    delay(2);

    FlagGPIO2 = true;
}

void LPressedButton(){
    /* botão da esquerda pressionado */
    HWREG(SOC_GPIO_1_SETDATAOUT) = (1 << 13);
    delay(4);
    HWREG(SOC_GPIO_1_CLEARDATAOUT) = (1 << 13);
    delay(4);

    HWREG(SOC_GPIO_1_SETDATAOUT) = (1 << 15);
    delay(4);
    HWREG(SOC_GPIO_1_CLEARDATAOUT) = (1 << 15);
    delay(4);

    HWREG(SOC_GPIO_1_SETDATAOUT) = (1 << 29);
    delay(4);
    HWREG(SOC_GPIO_1_CLEARDATAOUT) = (1 << 29);
    delay(4);

    FlagGPIO = true;
}

void NoButton() {
    /* nenhum botão pressionado*/
    HWREG(SOC_GPIO_1_CLEARDATAOUT) |= (1 << 21);
    HWREG(SOC_GPIO_1_CLEARDATAOUT) |= (1 << 22);
    HWREG(SOC_GPIO_1_CLEARDATAOUT) |= (1 << 23);
    HWREG(SOC_GPIO_1_CLEARDATAOUT) |= (1 << 24);
}