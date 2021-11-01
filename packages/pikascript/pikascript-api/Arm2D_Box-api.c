/* ******************************** */
/* Warning! Don't modify this file! */
/* ******************************** */
#include "Arm2D_Box.h"
#include "Arm2D_Element.h"
#include <stdio.h>
#include <stdlib.h>
#include "BaseObj.h"

void Arm2D_Box_initMethod(PikaObj *self, Args *args){
    Arm2D_Box_init(self);
}

void Arm2D_Box_setColorMethod(PikaObj *self, Args *args){
    char * color = args_getStr(args, "color");
    Arm2D_Box_setColor(self, color);
}

void Arm2D_Box_setSizeMethod(PikaObj *self, Args *args){
    int x = args_getInt(args, "x");
    int y = args_getInt(args, "y");
    Arm2D_Box_setSize(self, x, y);
}

void Arm2D_Box_updateMethod(PikaObj *self, Args *args){
    int bIsNewFrame = args_getInt(args, "bIsNewFrame");
    void * ptTile = args_getPtr(args, "ptTile");
    Arm2D_Box_update(self, bIsNewFrame, ptTile);
}

PikaObj *New_Arm2D_Box(Args *args){
    PikaObj *self = New_Arm2D_Element(args);
    class_defineMethod(self, "init()", Arm2D_Box_initMethod);
    class_defineMethod(self, "setColor(color:str)", Arm2D_Box_setColorMethod);
    class_defineMethod(self, "setSize(x:int,y:int)", Arm2D_Box_setSizeMethod);
    class_defineMethod(self, "update(ptTile:pointer,bIsNewFrame:int)", Arm2D_Box_updateMethod);
    return self;
}

Arg *Arm2D_Box(PikaObj *self){
    return arg_setMetaObj("", "Arm2D_Box", New_Arm2D_Box);
}
