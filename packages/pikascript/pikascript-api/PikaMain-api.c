/* ******************************** */
/* Warning! Don't modify this file! */
/* ******************************** */
#include "PikaMain.h"
#include "PikaStdLib_SysObj.h"
#include "Arm2D_Screen.h"
#include <stdio.h>
#include <stdlib.h>
#include "BaseObj.h"

PikaObj *New_PikaMain(Args *args){
    PikaObj *self = New_PikaStdLib_SysObj(args);
    obj_import(self, "Arm2D_Screen", New_Arm2D_Screen);
    obj_newObj(self, "screen", "Arm2D_Screen");
    return self;
}
