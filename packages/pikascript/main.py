import PikaStdLib
import Arm2D

mem = PikaStdLib.MemChecker()

screen = Arm2D.Screen()
screen.init()
screen.background.setColor('white')

screen.elems.s1 = Arm2D.Star()
screen.elems.s2 = Arm2D.Star()
screen.elems.s3 = Arm2D.Star()

screen.elems.s1.init()
screen.elems.s2.init()
screen.elems.s3.init()

screen.elems.s1.move(100, 300)
screen.elems.s1.speed(0.1)

screen.elems.s2.centra(100, 100)
screen.elems.s2.speed(0.5)

print('hello world')
print('mem used max:')
mem.max()
print('mem used now:')
mem.now()
