/* ******************************** */
/* Warning! Don't modify this file! */
/* ******************************** */
#include "Arm2D_ElementList.h"
#include "BaseObj.h"
#include <stdio.h>
#include <stdlib.h>
#include "BaseObj.h"

void Arm2D_ElementList_updateMethod(PikaObj *self, Args *args){
    Arm2D_ElementList_update(self);
}

PikaObj *New_Arm2D_ElementList(Args *args){
    PikaObj *self = New_BaseObj(args);
    class_defineMethod(self, "update()", Arm2D_ElementList_updateMethod);
    return self;
}
