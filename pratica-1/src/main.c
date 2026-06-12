#include "soc_AM335x.h"
#include "uart.h"

static void delay(){
    volatile unsigned int ra;
    for(ra = 0; ra < 1000000; ra ++);
}

int main(){
    const char *hello = "Hello World!!!\n\r";
    unsigned char *h = (unsigned char *)hello;
    while(1){
        printS(h,16);
        delay();
    }
}