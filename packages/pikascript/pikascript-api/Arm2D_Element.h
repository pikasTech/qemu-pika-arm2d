/* ******************************** */
/* Warning! Don't modify this file! */
/* ******************************** */
#ifndef __Arm2D_Element__H
#define __Arm2D_Element__H
#include <stdio.h>
#include <stdlib.h>
#include "PikaObj.h"

PikaObj *New_Arm2D_Element(Args *args);

void Arm2D_Element_down(PikaObj *self, int y);
void Arm2D_Element_init(PikaObj *self);
void Arm2D_Element_lift(PikaObj *self, int x);
void Arm2D_Element_move(PikaObj *self, int x, int y);
void Arm2D_Element_right(PikaObj *self, int x);
void Arm2D_Element_up(PikaObj *self, int y);

#endif
