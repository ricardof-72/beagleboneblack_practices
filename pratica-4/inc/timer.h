#ifndef TIMER_H
#define TIMER_H

static unsigned int DMTimerWritedPostedStatusGet();
void DMTimerCounterSet(unsigned int counter);
unsigned int DMTimerCounterGet();
void DMTimerEnable();
void DMTimerDisable();
void uDelay(unsigned int us);

#endif