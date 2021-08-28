import PikaStdLib
import Arm2D
import RtThread

box = Arm2D.Box()
remove('box')
mem = PikaStdLib.MemChecker()

screen = Arm2D.Screen()
screen.init()
screen.background.setColor('white')

print('hello world')

print('mem used max:')
mem.max()
print('mem used now:')
mem.now()