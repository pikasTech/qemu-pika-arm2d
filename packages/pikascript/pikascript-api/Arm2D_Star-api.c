/* ******************************** */
/* Warning! Don't modify this file! */
/* ******************************** */
#include "Arm2D_Star.h"
#include "Arm2D_Element.h"
#include <stdio.h>
#include <stdlib.h>
#include "BaseObj.h"

void Arm2D_Star_centraMethod(PikaObj *self, Args *args){
    int x = args_getInt(args, "x");
    int y = args_getInt(args, "y");
    Arm2D_Star_centra(self, x, y);
}

void Arm2D_Star_initMethod(PikaObj *self, Args *args){
    Arm2D_Star_init(self);
}

void Arm2D_Star_speedMethod(PikaObj *self, Args *args){
    float speed = args_getFloat(args, "speed");
    Arm2D_Star_speed(self, speed);
}

void Arm2D_Star_updateMethod(PikaObj *self, Args *args){
    int bIsNewFrame = args_getInt(args, "bIsNewFrame");
    void * ptTile = args_getPtr(args, "ptTile");
    Arm2D_Star_update(self, bIsNewFrame, ptTile);
}

PikaObj *New_Arm2D_Star(Args *args){
    PikaObj *self = New_Arm2D_Element(args);
    class_defineMethod(self, "centra(x:int,y:int)", Arm2D_Star_centraMethod);
    class_defineMethod(self, "init()", Arm2D_Star_initMethod);
    class_defineMethod(self, "speed(speed:float)", Arm2D_Star_speedMethod);
    class_defineMethod(self, "update(ptTile:pointer,bIsNewFrame:int)", Arm2D_Star_updateMethod);
    return self;
}

Arg *Arm2D_Star(PikaObj *self){
    return arg_setMetaObj("", "Arm2D_Star", New_Arm2D_Star);
}
