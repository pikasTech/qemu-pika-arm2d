import PikaStdLib
import Arm2D
import RtThread

# new and remove once to load class into classLoader in pikaMain
box = Arm2D.Box()
star = Arm2D.Star()
remove('box')
remove('star')

mem = PikaStdLib.MemChecker()

screen = Arm2D.Screen()
screen.init()
screen.background.setColor('white')
# screen.newBox('box1')
screen.elems.box1 = Arm2D.Box()
screen.elems.box1.init()
screen.elems.box1.move(250,250)
screen.elems.box1.setColor('red')

print('hello world')
print('mem used max:')
mem.max()
print('mem used now:')
mem.now()
