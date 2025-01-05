import pypampas

velocimeter = pypampas.Velocimeter()
velocimeter.definePin(17)
velocimeter.defineWheelDiameter(0.105)
velocimeter.defineAlpha(0.9)

while True:
    velocimeter.start()
    velocimeter.waitForUpdate(6)
    print("Speed: " + str(velocimeter.getSpeed()))