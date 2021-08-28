/* ******************************** */
/* Warning! Don't modify this file! */
/* ******************************** */
#include "Arm2D_Screen.h"
#include "BaseObj.h"
#include "Arm2D_BackGround.h"
#include "Arm2D_ElementList.h"
#include <stdio.h>
#include <stdlib.h>
#include "BaseObj.h"

void Arm2D_Screen_initMethod(PikaObj *self, Args *args){
    Arm2D_Screen_init(self);
}

void Arm2D_Screen_newBoxMethod(PikaObj *self, Args *args){
    char * name = args_getStr(args, "name");
    Arm2D_Screen_newBox(self, name);
}

void Arm2D_Screen_updateMethod(PikaObj *self, Args *args){
    void * bIsNewFrame = args_getPtr(args, "bIsNewFrame");
    void * ptTile = args_getPtr(args, "ptTile");
    Arm2D_Screen_update(self, bIsNewFrame, ptTile);
}

PikaObj *New_Arm2D_Screen(Args *args){
    PikaObj *self = New_BaseObj(args);
    obj_import(self, "Arm2D_BackGround", New_Arm2D_BackGround);
    obj_newObj(self, "background", "Arm2D_BackGround");
    obj_import(self, "Arm2D_ElementList", New_Arm2D_ElementList);
    obj_newObj(self, "elems", "Arm2D_ElementList");
    class_defineMethod(self, "init()", Arm2D_Screen_initMethod);
    class_defineMethod(self, "newBox(name:str)", Arm2D_Screen_newBoxMethod);
    class_defineMethod(self, "update(ptTile:pointer,bIsNewFrame:pointer)", Arm2D_Screen_updateMethod);
    return self;
}
