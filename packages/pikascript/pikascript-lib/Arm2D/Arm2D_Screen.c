#include "Arm2D_common.h"
extern PikaObj *pikaMain;

void Arm2D_Screen_newBox(PikaObj *self, char *name)
{
    Args *buffs = New_strBuff();
    obj_newObj(pikaMain, strsFormat(buffs, "screen.elems.%s", name), "Arm2D_Box");
    obj_run(pikaMain, strsFormat(buffs, "screen.elems.%s.init()", name));
    args_deinit(buffs);
}

void Arm2D_Screen_init(PikaObj *self)
{
    obj_run(self, "background.init()");
}

void Arm2D_Screen_update(PikaObj *self, void *ptTile)
{
    obj_setPtr(self, "ptTile", (void *)ptTile);
    obj_run(self, "background.update(ptTile)");
    obj_run(self, "elems.update(ptTile)");
}
