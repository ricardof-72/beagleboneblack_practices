#include "uart.h"
#include "soc_AM335x.h"

void putCh(unsigned char c){
    while(!(HWREG(SOC_UART_0_LSR) & (1<<5)));
    HWREG(SOC_UART_0_THR) = c;
}

unsigned int printS(unsigned char *str, unsigned int length){
    for(int i = 0; i < length; i++)
        putCh(str[i]);
    return(length);
}

char getCh(){
    while(!(HWREG(SOC_UART_0_LSR) & (1 << 0)));
    return HWREG(SOC_UART_0_RHR);
}

char Frase1(){
    const char *frase1 = "4seg\n\r";
    printS((unsigned char *)frase1, 6);
}

char Frase2(){
    const char *frase2 = "2seg\n\r";
    printS((unsigned char *)frase2, 6);
}