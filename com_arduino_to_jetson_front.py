import serial
import time

arduino = serial.Serial('/dev/ttyACM0', 9600, timeout=1)

while True:
    try:
        data = arduino.readline()
        if data:
            print(data)
            if "right" in data:
                if "10" in data: print("ok turn right 10 degrees")
                if "20" in data: print("ok turn right 20 degrees")
                if "30" in data: print("ok turn right 30 degrees")
                if "40" in data: print("ok turn right 40 degrees")
                if "50" in data: print("ok turn right 50 degrees")
            if "left" in data:
                if "10" in data: print("ok turn left 10 degrees")
                if "20" in data: print("ok turn left 20 degrees")
                if "30" in data: print("ok turn left 30 degrees")
                if "40" in data: print("ok turn left 40 degrees")
                if "50" in data: print("ok turn left 50 degrees")
        except:
            arduino.close()