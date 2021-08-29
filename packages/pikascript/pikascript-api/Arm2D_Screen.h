/* ******************************** */
/* Warning! Don't modify this file! */
/* ******************************** */
#ifndef __Arm2D_Screen__H
#define __Arm2D_Screen__H
#include <stdio.h>
#include <stdlib.h>
#include "PikaObj.h"

PikaObj *New_Arm2D_Screen(Args *args);

void Arm2D_Screen_init(PikaObj *self);
void Arm2D_Screen_newBox(PikaObj *self, char * name);
void Arm2D_Screen_newStar(PikaObj *self, char * name);
void Arm2D_Screen_update(PikaObj *self, int bIsNewFrame, void * ptTile);

#endif
