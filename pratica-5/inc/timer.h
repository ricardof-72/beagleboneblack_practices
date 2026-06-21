#ifndef TIMER_H
#define TIMER_H

#define DMTimerWaitForWrite(reg) \
    if(HWREG(DMTIMER7_TSICR) & (1 << 2)) \
    while((reg & DMTimerWritedPostedStatusGet()));

unsigned int DMTimerWritedPostedStatusGet();
void DMTimerCounterSet(unsigned int counter);
unsigned int DMTimerCounterGet();
void DMTimerEnable();
void DMTimerDisable();

#endif