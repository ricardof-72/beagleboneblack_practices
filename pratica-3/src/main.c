#include "soc_AM335x.h"
#include "system_init.h"
#include "func_buttons.h"

void delay(volatile unsigned int ms) {
    for(volatile unsigned int i = 0; i < ms; i++);
}
 
int main() {

SystemInit();

while(1){
        if (!(HWREG(SOC_GPIO_1_DATAIN) & (1 << 28))){
            LeftButton();
        } else if (!(HWREG(SOC_GPIO_1_DATAIN) & (1 << 29))) {
            RightButton();
        } else {
            NoButton();
        }
    }
}