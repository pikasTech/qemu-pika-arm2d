/* ******************************** */
/* Warning! Don't modify this file! */
/* ******************************** */
#ifndef __Arm2D_Star__H
#define __Arm2D_Star__H
#include <stdio.h>
#include <stdlib.h>
#include "PikaObj.h"

PikaObj *New_Arm2D_Star(Args *args);

void Arm2D_Star_centra(PikaObj *self, int x, int y);
void Arm2D_Star_init(PikaObj *self);
void Arm2D_Star_speed(PikaObj *self, float speed);
void Arm2D_Star_update(PikaObj *self, int bIsNewFrame, void * ptTile);

#endif
