/* ******************************** */
/* Warning! Don't modify this file! */
/* ******************************** */
#include "Arm2D_Box.h"
#include "Arm2D_Element.h"
#include <stdio.h>
#include <stdlib.h>
#include "BaseObj.h"

void Arm2D_Box_setColorMethod(PikaObj *self, Args *args){
    Arm2D_Box_setColor(self);
}

void Arm2D_Box_setSizeMethod(PikaObj *self, Args *args){
    int x = args_getInt(args, "x");
    int y = args_getInt(args, "y");
    Arm2D_Box_setSize(self, x, y);
}

PikaObj *New_Arm2D_Box(Args *args){
    PikaObj *self = New_Arm2D_Element(args);
    class_defineMethod(self, "setColor()", Arm2D_Box_setColorMethod);
    class_defineMethod(self, "setSize(x:int,y:int)", Arm2D_Box_setSizeMethod);
    return self;
}
