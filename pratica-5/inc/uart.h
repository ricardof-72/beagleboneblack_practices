#ifndef UART_H
#define UART_H

/* funcao para receber a entrada */
void putCh(unsigned char c);

/* funcao para exibir uma mensagem na tela */
unsigned int printS(unsigned char *str, unsigned int length);

/* funcao para ler a entrada */
char getCh();

/* imprime a frase de quando o botao direito for pressionado */
char Frase1();

/* imprime a frase de quando o botao esquerdo for pressionado */
char Frase2();

#endif