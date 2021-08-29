/* ******************************** */
/* Warning! Don't modify this file! */
/* ******************************** */
#include "PikaMain.h"
#include <stdio.h>
#include <stdlib.h>

PikaObj * pikaScriptInit(){
    PikaObj * pikaMain = newRootObj("pikaMain", New_PikaMain);
    obj_run(pikaMain, "remove('box')");
    obj_run(pikaMain, "remove('star')");
    obj_run(pikaMain, "screen.init()");
    obj_run(pikaMain, "screen.background.setColor('white')");
    obj_run(pikaMain, "screen.elems.s1.init()");
    obj_run(pikaMain, "print('hello world')");
    obj_run(pikaMain, "print('mem used max:')");
    obj_run(pikaMain, "mem.max()");
    obj_run(pikaMain, "print('mem used now:')");
    obj_run(pikaMain, "mem.now()");
    return pikaMain;
}

