/* ******************************** */
/* Warning! Don't modify this file! */
/* ******************************** */
#ifndef __Arm2D_Box__H
#define __Arm2D_Box__H
#include <stdio.h>
#include <stdlib.h>
#include "PikaObj.h"

PikaObj *New_Arm2D_Box(Args *args);

void Arm2D_Box_init(PikaObj *self);
void Arm2D_Box_setColor(PikaObj *self, char * color);
void Arm2D_Box_setSize(PikaObj *self, int x, int y);
void Arm2D_Box_update(PikaObj *self, int bIsNewFrame, void * ptTile);

#endif
