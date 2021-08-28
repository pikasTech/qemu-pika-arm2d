from PikaObj import *


class BackGround(TinyObj):
    def init():
        pass

    def setColor(color: str):
        pass

    def getColor() -> str:
        pass


class Screen(BaseObj):
    background = BackGround()
