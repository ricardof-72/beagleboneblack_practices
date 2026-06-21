#ifndef TIMER_H
#define TIMER_H
#define TIMER_1US_COUNT 24000000

/* define uma funcao usada para isolar um bit especifico para verificacao. 
   Depois verifica se o bit 2 esta em posted mode, se estiver avanca para o while
   no while, o codigo fica travado esperando a escrita terminar */
static unsigned int DMTimerWritedPostedStatusGet();


void DMTimerCounterSet(unsigned int counter);
unsigned int DMTimerCounterGet();
void DMTimerEnable();
void DMTimerDisable();
void uDelay(unsigned int us);

#endif