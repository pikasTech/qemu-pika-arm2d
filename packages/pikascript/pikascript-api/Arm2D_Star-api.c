/* ******************************** */
/* Warning! Don't modify this file! */
/* ******************************** */
#include "Arm2D_Star.h"
#include "Arm2D_Element.h"
#include <stdio.h>
#include <stdlib.h>
#include "BaseObj.h"

void Arm2D_Star_initMethod(PikaObj *self, Args *args){
    Arm2D_Star_init(self);
}

void Arm2D_Star_updateMethod(PikaObj *self, Args *args){
    int bIsNewFrame = args_getInt(args, "bIsNewFrame");
    void * ptTile = args_getPtr(args, "ptTile");
    Arm2D_Star_update(self, bIsNewFrame, ptTile);
}

PikaObj *New_Arm2D_Star(Args *args){
    PikaObj *self = New_Arm2D_Element(args);
    class_defineMethod(self, "init()", Arm2D_Star_initMethod);
    class_defineMethod(self, "update(ptTile:pointer,bIsNewFrame:int)", Arm2D_Star_updateMethod);
    return self;
}
