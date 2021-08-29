/* ******************************** */
/* Warning! Don't modify this file! */
/* ******************************** */
#include "Arm2D_BackGround.h"
#include "TinyObj.h"
#include <stdio.h>
#include <stdlib.h>
#include "BaseObj.h"

void Arm2D_BackGround_getColorMethod(PikaObj *self, Args *args){
    char * res = Arm2D_BackGround_getColor(self);
    method_returnStr(args, res);
}

void Arm2D_BackGround_initMethod(PikaObj *self, Args *args){
    Arm2D_BackGround_init(self);
}

void Arm2D_BackGround_setColorMethod(PikaObj *self, Args *args){
    char * color = args_getStr(args, "color");
    Arm2D_BackGround_setColor(self, color);
}

void Arm2D_BackGround_updateMethod(PikaObj *self, Args *args){
    int bIsNewFrame = args_getInt(args, "bIsNewFrame");
    void * ptTile = args_getPtr(args, "ptTile");
    Arm2D_BackGround_update(self, bIsNewFrame, ptTile);
}

PikaObj *New_Arm2D_BackGround(Args *args){
    PikaObj *self = New_TinyObj(args);
    class_defineMethod(self, "getColor()->str", Arm2D_BackGround_getColorMethod);
    class_defineMethod(self, "init()", Arm2D_BackGround_initMethod);
    class_defineMethod(self, "setColor(color:str)", Arm2D_BackGround_setColorMethod);
    class_defineMethod(self, "update(ptTile:pointer,bIsNewFrame:int)", Arm2D_BackGround_updateMethod);
    return self;
}
