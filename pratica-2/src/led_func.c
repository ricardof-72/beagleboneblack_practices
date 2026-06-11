#include "led_func.h"

#include "soc_AM335x.h"

void LedFunc() {
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