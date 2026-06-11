#include "soc_AM335x.h"
#include "timer.h"
#include "uart.h"
#include "system_init.h"

int main() {
// Inicializacao dos clocks e configuracao do timer
SystemInit();

while(1){
        const char *frase = "Digite o tempo: ";
        unsigned char *c = (unsigned char *)frase;
        printS(c, 16);

        char ch = getCh();
        putCh(ch);

        if (ch >= '0' && ch <= '9'){
            unsigned int convert = ch - '0';
            while(1){
                // Loop para mostrar o led acendendo e apagando, conforme o delay feito
                HWREG(SOC_GPIO_1_SETDATAOUT) = (1 << 28);
                uDelay(convert);
                HWREG(SOC_GPIO_1_CLEARDATAOUT) = (1 << 28);
                uDelay(convert);
            }
        } else {
            const char *excecao = "Tempo invalido, digite de 0 a 9\n\r";
            unsigned char *e = (unsigned char *)excecao;
            printS(e, 33);
        }
    }
}