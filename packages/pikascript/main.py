import PikaStdLib

import RtThread

print('hello world')
mem = PikaStdLib.MemChecker()
print('mem.max :')
mem.max()
print('mem.now :')
mem.now()