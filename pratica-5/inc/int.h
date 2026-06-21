#ifndef INT_H
#define INT_H
#include "stdbool.h"

/* funcao para iniciar as interrupcoes */
void IntAINTCInit();

/* funcao para as interrupcoes relacionadas aos GPIOs */
void gpioIsr();

/* funcao para as interrupcoes relacionadas ao DMTIMER */
void DMTimerIsr();

/* interrupt service routine */
void ISRHandler();

#endif
