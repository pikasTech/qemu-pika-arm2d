/* ******************************** */
/* Warning! Don't modify this file! */
/* ******************************** */
#include "RtThread_Time.h"
#include "TinyObj.h"
#include <stdio.h>
#include <stdlib.h>
#include "BaseObj.h"

void RtThread_Time_delayMethod(PikaObj *self, Args *args){
    int s = args_getInt(args, "s");
    RtThread_Time_delay(self, s);
}

void RtThread_Time_delay_msMethod(PikaObj *self, Args *args){
    int ms = args_getInt(args, "ms");
    RtThread_Time_delay_ms(self, ms);
}

PikaObj *New_RtThread_Time(Args *args){
    PikaObj *self = New_TinyObj(args);
    class_defineMethod(self, "delay(s:int)", RtThread_Time_delayMethod);
    class_defineMethod(self, "delay_ms(ms:int)", RtThread_Time_delay_msMethod);
    return self;
}
