#include "Arm2d_common.h"

void Arm2D_Star_init(PikaObj *self)
{
    obj_setInt(self, "posX", 250);
    obj_setInt(self, "posY", 250);
    obj_setInt(self, "centreX", 0);
    obj_setInt(self, "centreY", 0);
    obj_setFloat(self, "angleSpeed", 3.0f);
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

void Arm2D_Star_update(PikaObj *self, int bIsNewFrame, void *ptTile)
{
    s_tSun.fAngleSpeed = obj_getFloat(self, "angleSpeed");
    s_tSun.tCentre.iX = obj_getInt(self, "centreX");
    s_tSun.tCentre.iY = obj_getInt(self, "centreY");
    s_tSun.tRegion.tLocation.iX = obj_getInt(self, "posX");
    s_tSun.tRegion.tLocation.iY = obj_getInt(self, "posY");

    arm_2dp_rgb565_tile_rotation(&(s_tSun.tOP),
                                 s_tSun.ptTile,
                                 ptTile,
                                 &(s_tSun.tRegion),
                                 s_tSun.tCentre,
                                 s_tSun.fAngle,
                                 GLCD_COLOR_WHITE);
}
