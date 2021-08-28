/* ******************************** */
/* Warning! Don't modify this file! */
/* ******************************** */
#include "Arm2D_ElementList.h"
#include "BaseObj.h"
#include <stdio.h>
#include <stdlib.h>
#include "BaseObj.h"

void Arm2D_ElementList_updateMethod(PikaObj *self, Args *args){
    void * ptTile = args_getPtr(args, "ptTile");
    Arm2D_ElementList_update(self, ptTile);
}

PikaObj *New_Arm2D_ElementList(Args *args){
    PikaObj *self = New_BaseObj(args);
    class_defineMethod(self, "update(ptTile:pointer)", Arm2D_ElementList_updateMethod);
    return self;
}
