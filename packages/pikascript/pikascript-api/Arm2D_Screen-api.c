/* ******************************** */
/* Warning! Don't modify this file! */
/* ******************************** */
#include "Arm2D_Screen.h"
#include "BaseObj.h"
#include "Arm2D_BackGround.h"
#include <stdio.h>
#include <stdlib.h>
#include "BaseObj.h"

PikaObj *New_Arm2D_Screen(Args *args){
    PikaObj *self = New_BaseObj(args);
    obj_import(self, "Arm2D_BackGround", New_Arm2D_BackGround);
    obj_newObj(self, "background", "Arm2D_BackGround");
    return self;
}
