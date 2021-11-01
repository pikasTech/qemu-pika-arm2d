/* ******************************** */
/* Warning! Don't modify this file! */
/* ******************************** */
#include "Arm2D_Element.h"
#include "TinyObj.h"
#include <stdio.h>
#include <stdlib.h>
#include "BaseObj.h"

void Arm2D_Element_downMethod(PikaObj *self, Args *args){
    int y = args_getInt(args, "y");
    Arm2D_Element_down(self, y);
}

void Arm2D_Element_initMethod(PikaObj *self, Args *args){
    Arm2D_Element_init(self);
}

void Arm2D_Element_liftMethod(PikaObj *self, Args *args){
    int x = args_getInt(args, "x");
    Arm2D_Element_lift(self, x);
}

void Arm2D_Element_moveMethod(PikaObj *self, Args *args){
    int x = args_getInt(args, "x");
    int y = args_getInt(args, "y");
    Arm2D_Element_move(self, x, y);
}

void Arm2D_Element_rightMethod(PikaObj *self, Args *args){
    int x = args_getInt(args, "x");
    Arm2D_Element_right(self, x);
}

void Arm2D_Element_upMethod(PikaObj *self, Args *args){
    int y = args_getInt(args, "y");
    Arm2D_Element_up(self, y);
}

void Arm2D_Element_updateMethod(PikaObj *self, Args *args){
    int bIsNewFrame = args_getInt(args, "bIsNewFrame");
    void * ptTile = args_getPtr(args, "ptTile");
    Arm2D_Element_update(self, bIsNewFrame, ptTile);
}

PikaObj *New_Arm2D_Element(Args *args){
    PikaObj *self = New_TinyObj(args);
    class_defineMethod(self, "down(y:int)", Arm2D_Element_downMethod);
    class_defineMethod(self, "init()", Arm2D_Element_initMethod);
    class_defineMethod(self, "lift(x:int)", Arm2D_Element_liftMethod);
    class_defineMethod(self, "move(x:int,y:int)", Arm2D_Element_moveMethod);
    class_defineMethod(self, "right(x:int)", Arm2D_Element_rightMethod);
    class_defineMethod(self, "up(y:int)", Arm2D_Element_upMethod);
    class_defineMethod(self, "update(ptTile:pointer,bIsNewFrame:int)", Arm2D_Element_updateMethod);
    return self;
}

Arg *Arm2D_Element(PikaObj *self){
    return arg_setMetaObj("", "Arm2D_Element", New_Arm2D_Element);
}
