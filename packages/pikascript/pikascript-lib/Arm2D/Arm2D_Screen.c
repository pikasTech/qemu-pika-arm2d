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

rotate_tile_t s_tSun = {
    .ptTile = &c_tPictureSun,
    .fAngleSpeed = 3.0f,
    .tCentre = {
        .iX = 0,
        .iY = 0,
    },
    .tRegion = {
        .tLocation = {
            .iX = 200,
            .iY = 200,
        },
        .tSize = c_tPictureSun.tRegion.tSize,
    },
    .fAngle = 0.0,
};

void Arm2D_Screen_update(PikaObj *self, void * bIsNewFrame, void * ptTile)
{
    obj_setPtr(self, "ptTile", (void *)ptTile);
    obj_run(self, "background.update(ptTile)");
    obj_run(self, "elems.update(ptTile)");

    arm_2dp_rgb565_tile_rotation(&(s_tSun.tOP),
                                  s_tSun.ptTile,
                                  ptTile,
                                  &(s_tSun.tRegion),
                                  s_tSun.tCentre,
                                  s_tSun.fAngle,
                                  GLCD_COLOR_WHITE);
    // arm_2d_rgb16_tile_copy_with_colour_masking(&c_tPictureSun,
    //                                            ptTile,
    //                                            &tSunRegion,
    //                                            GLCD_COLOR_WHITE,
    //                                            ARM_2D_CP_MODE_FILL);
}
