#include "soc_AM335x.h"
#include "system_init.h"
#include "led_func.h"

int main() {
SystemInit();

while(1){
        LedFunc();
    }    
}