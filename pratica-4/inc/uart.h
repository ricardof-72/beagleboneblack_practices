#ifndef UART_H
#define UART_H

/* enquanto o bit 5 do registrador nao for 1, fica travando esperando */
void putCh(unsigned char c);
/* enquanto i for menor que o tamanho, ele vai inserir o caractere */
unsigned int printS(unsigned char *str, unsigned int length);
/* enquanto o bit 0 do registrador nao for 1, fica travado esperando */
char getCh();

#endif