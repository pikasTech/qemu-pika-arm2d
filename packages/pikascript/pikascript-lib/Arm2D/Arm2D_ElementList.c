#include "Arm2D_common.h"

int32_t __foreach_ElementList_update(Arg *elem, Args *buffs)
{
    char *type = arg_getType(elem);
    void *ptTile = args_getPtr(buffs, "ptTile");
    if (strIsStartWith(type, "_class"))
    {
        PikaObj *elemObj = arg_getPtr(elem);
        obj_setPtr(elemObj, "ptTile", ptTile);
        obj_run(elemObj, "update(ptTile)");
    }
    return 0;
}

void Arm2D_ElementList_update(PikaObj *self, void *ptTile)
{
    Args *buffs = New_args(NULL);
    args_setPtr(buffs, "ptTile", (void *)ptTile);
    args_foreach(self->attributeList, __foreach_ElementList_update, buffs);
    args_deinit(buffs);
}