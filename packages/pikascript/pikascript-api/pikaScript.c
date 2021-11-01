/* ******************************** */
/* Warning! Don't modify this file! */
/* ******************************** */
#include "PikaMain.h"
#include <stdio.h>
#include <stdlib.h>

PikaObj * pikaScriptInit(){
    PikaObj * pikaMain = newRootObj("pikaMain", New_PikaMain);
    obj_run(pikaMain,
            "\n"
            "mem = PikaStdLib.MemChecker()\n"
            "\n"
            "screen = Arm2D.Screen()\n"
            "screen.init()\n"
            "screen.background.setColor('white')\n"
            "\n"
            "screen.elems.s1 = Arm2D.Star()\n"
            "screen.elems.s2 = Arm2D.Star()\n"
            "screen.elems.s3 = Arm2D.Star()\n"
            "\n"
            "screen.elems.s1.init()\n"
            "screen.elems.s2.init()\n"
            "screen.elems.s3.init()\n"
            "\n"
            "screen.elems.s1.move(100, 300)\n"
            "screen.elems.s1.speed(0.1)\n"
            "\n"
            "screen.elems.s2.centra(100, 100)\n"
            "screen.elems.s2.speed(0.5)\n"
            "\n"
            "print('hello world')\n"
            "print('mem used max:')\n"
            "mem.max()\n"
            "print('mem used now:')\n"
            "mem.now()\n"
            "\n"
            "\n");
    return pikaMain;
}

