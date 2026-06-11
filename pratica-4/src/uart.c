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