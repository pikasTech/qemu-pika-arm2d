/* ******************************** */
/* Warning! Don't modify this file! */
/* ******************************** */
#include "PikaMain.h"
#include "PikaStdLib_SysObj.h"
#include "Arm2D_Box.h"
#include "PikaStdLib_MemChecker.h"
#include "Arm2D_Screen.h"
#include "Arm2D_Box.h"
#include "Arm2D_Star.h"
#include <stdio.h>
#include <stdlib.h>
#include "BaseObj.h"

PikaObj *New_PikaMain(Args *args){
    PikaObj *self = New_PikaStdLib_SysObj(args);
    obj_import(self, "Arm2D_Box", New_Arm2D_Box);
    obj_newObj(self, "box", "Arm2D_Box");
    obj_import(self, "PikaStdLib_MemChecker", New_PikaStdLib_MemChecker);
    obj_newObj(self, "mem", "PikaStdLib_MemChecker");
    obj_import(self, "Arm2D_Screen", New_Arm2D_Screen);
    obj_newObj(self, "screen", "Arm2D_Screen");
    obj_import(self, "Arm2D_Box", New_Arm2D_Box);
    obj_newObj(self, "screen.elems.box1", "Arm2D_Box");
    obj_import(self, "Arm2D_Star", New_Arm2D_Star);
    obj_newObj(self, "star", "Arm2D_Star");
    return self;
}
