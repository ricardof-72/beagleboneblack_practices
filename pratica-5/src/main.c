#include "soc_AM335x.h"
#include "system_init.h"
#include "timer.h"
#include "int.h"
#include "func_buttons.h"
#include "uart.h"

int main() {
    /* Inicialização dos GPIOs e das interrupções */
    SystemInit();
    IntAINTCInit();
 
    while(1) {
        if(FlagGPIO == false){
            Frase1();
            /* botão 1 pressionado */
            LPressedButton();
        }
        else if(FlagGPIO2 == false){
            Frase2();
            /* botão 2 pressionado */
            RPressedButton();
        }
        else {
            NoButton();
        }
    }
}
