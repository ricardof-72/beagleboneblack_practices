#include "func_buttons.h"

#include "soc_AM335x.h"

void LeftButton() {
    /* botão da esquerda pressionado */

    HWREG(SOC_GPIO_1_SETDATAOUT) = (1 << 21);
    delay(2500000);
    HWREG(SOC_GPIO_1_CLEARDATAOUT) = (1 << 21);

    HWREG(SOC_GPIO_1_SETDATAOUT) = (1 << 22);
    delay(2500000);
    HWREG(SOC_GPIO_1_CLEARDATAOUT) = (1 << 22);

    HWREG(SOC_GPIO_1_SETDATAOUT) = (1 << 23);
    delay(2500000);
    HWREG(SOC_GPIO_1_CLEARDATAOUT) = (1 << 23);

    HWREG(SOC_GPIO_1_SETDATAOUT) = (1 << 24);
    delay(2500000);
    HWREG(SOC_GPIO_1_CLEARDATAOUT) = (1 << 24);
}

void RightButton() {
    /* botão da direita pressionado */

    HWREG(SOC_GPIO_1_SETDATAOUT) = (1 << 24);
    delay(2500000);
    HWREG(SOC_GPIO_1_CLEARDATAOUT) = (1 << 24);

    HWREG(SOC_GPIO_1_SETDATAOUT) = (1 << 23);
    delay(2500000);
    HWREG(SOC_GPIO_1_CLEARDATAOUT) = (1 << 23);

    HWREG(SOC_GPIO_1_SETDATAOUT) = (1 << 22);
    delay(2500000);
    HWREG(SOC_GPIO_1_CLEARDATAOUT) = (1 << 22);

    HWREG(SOC_GPIO_1_SETDATAOUT) = (1 << 21);
    delay(2500000);
    HWREG(SOC_GPIO_1_CLEARDATAOUT) = (1 << 21);
}

void NoButton() {
     /* nenhum botão pressionado*/

    HWREG(SOC_GPIO_1_CLEARDATAOUT) = (1 << 21);

    HWREG(SOC_GPIO_1_CLEARDATAOUT) = (1 << 22);

    HWREG(SOC_GPIO_1_CLEARDATAOUT) = (1 << 23);

    HWREG(SOC_GPIO_1_CLEARDATAOUT) = (1 << 24);
}