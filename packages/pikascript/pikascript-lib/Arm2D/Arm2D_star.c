#include "Arm2d_common.h"
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

void Arm2D_Star_init(PikaObj *self)
{
    obj_setInt(self, "posX", 0);
    obj_setInt(self, "posY", 0);
    obj_setInt(self, "centreX", 0);
    obj_setInt(self, "centreY", 0);
    obj_setFloat(self, "angleSpeed", 3.0f);
}

void Arm2D_Star_update(PikaObj *self, int bIsNewFrame, void *ptTile)
{
    rotate_tile_t s_tSun = {
        .ptTile = &c_tPictureSun,
        .fAngleSpeed = obj_getFloat(self, "angleSpeed"),
        .tCentre = {
            .iX = obj_getInt(self, "centreX"),
            .iY = obj_getInt(self, "cretreY"),
        },
        .tRegion = {
            .tLocation = {
                .iX = obj_getInt(self, "posX"),
                .iY = obj_getInt(self, "posY"),
            },
            .tSize = c_tPictureSun.tRegion.tSize,
        },
        .fAngle = 0.0,
    };

    arm_2dp_rgb565_tile_rotation(&(s_tSun.tOP),
                                 s_tSun.ptTile,
                                 ptTile,
                                 &(s_tSun.tRegion),
                                 s_tSun.tCentre,
                                 s_tSun.fAngle,
                                 GLCD_COLOR_WHITE);
}