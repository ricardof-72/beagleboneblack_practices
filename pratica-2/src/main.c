#include "soc_AM335x.h"
#include "system_init.h"
#include "led_func.h"

int main() {
    /* loop para piscar os leds, internos e o externo, em uma sequência específica */
    while(1){
        LedFunc();
    }    
}

