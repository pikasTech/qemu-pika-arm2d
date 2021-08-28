import PikaStdLib
import Arm2D
import RtThread

box = Arm2D.Box()
remove('box')

screen = Arm2D.Screen()
screen.init()
screen.background.setColor('white')

print('hello world')