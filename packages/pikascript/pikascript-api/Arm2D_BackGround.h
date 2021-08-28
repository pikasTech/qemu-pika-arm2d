/* ******************************** */
/* Warning! Don't modify this file! */
/* ******************************** */
#ifndef __Arm2D_BackGround__H
#define __Arm2D_BackGround__H
#include <stdio.h>
#include <stdlib.h>
#include "PikaObj.h"

PikaObj *New_Arm2D_BackGround(Args *args);

char * Arm2D_BackGround_getColor(PikaObj *self);
void Arm2D_BackGround_init(PikaObj *self);
void Arm2D_BackGround_setColor(PikaObj *self, char * color);

#endif
