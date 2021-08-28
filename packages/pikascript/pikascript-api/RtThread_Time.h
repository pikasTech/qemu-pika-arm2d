/* ******************************** */
/* Warning! Don't modify this file! */
/* ******************************** */
#ifndef __RtThread_Time__H
#define __RtThread_Time__H
#include <stdio.h>
#include <stdlib.h>
#include "PikaObj.h"

PikaObj *New_RtThread_Time(Args *args);

void RtThread_Time_delay(PikaObj *self, int s);
void RtThread_Time_delay_ms(PikaObj *self, int ms);

#endif
