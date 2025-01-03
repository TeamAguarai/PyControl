import pycontrol

velocimeter = pycontrol.Velocimeter()
velocimeter.definePin(17)
velocimeter.defineWheelDiameter(0.105)
velocimeter.defineAlpha(0.9)

while True:
    velocimeter.start()
    velocimeter.waitForUpdate()
    print("Speed: " + velocimeter.getSpeed())