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

extern PikaObj *pikaMain;

void Arm2D_BackGround_init(PikaObj *self)
{
    obj_setStr(self, "color", "white");
}

char * Arm2D_BackGround_getColor(PikaObj *self)
{
    return obj_getStr(self, "color");
}

void Arm2D_BackGround_setColor(PikaObj *self, char * color)
{
    obj_setStr(self, "color", color);
}


