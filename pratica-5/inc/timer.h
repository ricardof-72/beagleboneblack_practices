#ifndef TIMER_H
#define TIMER_H

/* funcao de espera para escrever */
#define DMTimerWaitForWrite(reg) \
    if(HWREG(DMTIMER7_TSICR) & (1 << 2)) \
    while((reg & DMTimerWritedPostedStatusGet()));

/* funcao para retonar o valor do TWPS */
unsigned int DMTimerWritedPostedStatusGet();

/* funcao para setar o valor do contador */
void DMTimerCounterSet(unsigned int counter);\

/* funcao para retornar o valor do contador */
unsigned int DMTimerCounterGet();

/* ativacao do timer */
void DMTimerEnable();

/* desativacao do timer */
void DMTimerDisable();

/* funcao que coloca um delay usando interrupcao */
void delay(unsigned int mSec);

#endif