#include "Arm2D_common.h"

void Arm2D_Box_init(PikaObj *self)
{
    obj_setInt(self, "posX", 0);
    obj_setInt(self, "posY", 0);
    obj_setInt(self, "sizeX", 50);
    obj_setInt(self, "sizeY", 50);
    obj_setStr(self, "color", "blue");
}
void Arm2D_Box_setColor(PikaObj *self, char *color)
{
    obj_setStr(self, "color", color);
}
void Arm2D_Box_setSize(PikaObj *self, int x, int y)
{
    obj_setInt(self, "sizeX", x);
    obj_setInt(self, "sizeY", y);
}
