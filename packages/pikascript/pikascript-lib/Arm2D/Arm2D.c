/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-08-28     lyon       the first version
 */
#include "arm_2d.h"
#include "arm_2d_helper.h"
#include "lcd_printf.h"
#include "pikaScript.h"
#include "app-arm2d.h"
#include "Arm2D_Box.h"
#include "dataStrs.h"

extern PikaObj *pikaMain;

uint16_t getColorCode(char *colorName)
{
    if (strEqu("white", colorName))
    {
        return GLCD_COLOR_WHITE;
    }
    if (strEqu("black", colorName))
    {
        return GLCD_COLOR_BLACK;
    }
    if (strEqu("red", colorName))
    {
        return GLCD_COLOR_RED;
    }
    if (strEqu("blue", colorName))
    {
        return GLCD_COLOR_BLUE;
    }
    if (strEqu("green", colorName))
    {
        return GLCD_COLOR_GREEN;
    }
}

void Arm2D_Box_setColor(PikaObj *self)
{
}
void Arm2D_Box_setSize(PikaObj *self, int x, int y)
{
}

void Arm2D_Element_down(PikaObj *self, int y)
{
}

void Arm2D_Element_init(PikaObj *self)
{
}

void Arm2D_Element_lift(PikaObj *self, int x)
{
}

void Arm2D_Element_move(PikaObj *self, int x, int y)
{
}

void Arm2D_Element_right(PikaObj *self, int x)
{
}

void Arm2D_Element_up(PikaObj *self, int y)
{
}

void Arm2D_Screen_addBox(PikaObj *self, char *name)
{
    Args *buffs = New_strBuff();
    char *objPath = strsAppend(buffs, "screen.elems.", name);
    obj_newObj(pikaMain, objPath, "Arm2D_Box");
    args_deinit(buffs);
}

void Arm2D_Screen_init(PikaObj *self)
{
    obj_run(self, "background.init()");
}

void Arm2D_Screen_update(PikaObj *self, void *ptTile)
{
    char *color = obj_getStr(self, "background.color");
    uint16_t backGroundColor = getColorCode(color);
    arm_2d_rgb16_fill_colour(ptTile, NULL, backGroundColor);
}

void Arm2D_BackGround_init(PikaObj *self)
{
    obj_setStr(self, "color", "white");
}

char *Arm2D_BackGround_getColor(PikaObj *self)
{
    return obj_getStr(self, "color");
}

void Arm2D_BackGround_setColor(PikaObj *self, char *color)
{
    obj_setStr(self, "color", color);
}
