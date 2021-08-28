#include "Arm2D_common.h"

void Arm2D_BackGround_init(PikaObj *self)
{
    obj_setStr(self, "color", "white");
}

char *Arm2D_BackGround_getColor(PikaObj *self)
{
    return obj_getStr(self, "color");
}

void Arm2D_BackGround_setColor(PikaObj *self, char *color)
{
    obj_setStr(self, "color", color);
}
