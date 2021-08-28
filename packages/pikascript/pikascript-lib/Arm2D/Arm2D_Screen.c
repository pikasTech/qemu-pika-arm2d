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

extern const uint8_t c_bmpSun[56 * 57 * sizeof(uint16_t)];
const static arm_2d_tile_t c_tPictureSun = {
    .tRegion = {
        .tSize = {
            .iWidth = 56,
            .iHeight = 57},
    },
    .tInfo.bIsRoot = true,
    .phwBuffer = (uint16_t *)c_bmpSun,
};

void Arm2D_Screen_update(PikaObj *self, void *ptTile)
{
    obj_setPtr(self, "ptTile", (void *)ptTile);
    obj_run(self, "background.update(ptTile)");
    obj_run(self, "elems.update(ptTile)");
    arm_2d_rgb16_tile_copy_with_colour_masking(&c_tPictureSun,
                                               ptTile,
                                               NULL,
                                               GLCD_COLOR_WHITE,
                                               ARM_2D_CP_MODE_FILL);
}
