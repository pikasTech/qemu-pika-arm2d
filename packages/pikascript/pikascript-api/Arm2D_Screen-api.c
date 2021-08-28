/* ******************************** */
/* Warning! Don't modify this file! */
/* ******************************** */
#include "Arm2D_Screen.h"
#include "BaseObj.h"
#include "Arm2D_BackGround.h"
#include <stdio.h>
#include <stdlib.h>
#include "BaseObj.h"

void Arm2D_Screen_initMethod(PikaObj *self, Args *args){
    Arm2D_Screen_init(self);
}

void Arm2D_Screen_updateMethod(PikaObj *self, Args *args){
    void * ptTile = args_getPtr(args, "ptTile");
    Arm2D_Screen_update(self, ptTile);
}

PikaObj *New_Arm2D_Screen(Args *args){
    PikaObj *self = New_BaseObj(args);
    obj_import(self, "Arm2D_BackGround", New_Arm2D_BackGround);
    obj_newObj(self, "background", "Arm2D_BackGround");
    class_defineMethod(self, "init()", Arm2D_Screen_initMethod);
    class_defineMethod(self, "update(ptTile:pointer)", Arm2D_Screen_updateMethod);
    return self;
}
