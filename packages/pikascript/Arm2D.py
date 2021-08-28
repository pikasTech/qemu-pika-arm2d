from PikaObj import *


class BackGround(TinyObj):
    def init():
        pass

    def setColor(color: str):
        pass

    def getColor() -> str:
        pass


class ElementList(BaseObj):
    def update():
        pass


class Element(TinyObj):
    def init():
        pass

    def move(x: int, y: int):
        pass

    def right(x: int):
        pass

    def lift(x: int):
        pass

    def up(y: int):
        pass

    def down(y: int):
        pass

    def update():
        pass

class Box(Element):
#   override
    def update():
        pass

    def init():
        pass

    def setColor(color: str):
        pass

    def setSize(x: int, y: int):
        pass


class Screen(BaseObj):
    background = BackGround()
    elems = ElementList()

    def newBox(name: str):
        pass

    def init():
        pass

    def update(ptTile: pointer):
        pass
