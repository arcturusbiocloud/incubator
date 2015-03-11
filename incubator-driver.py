import serial
import time

print("Arcturus Incubator and lights controller python driver")
print("Waiting connection to the controller ...")

serial_port = serial.Serial( port="/dev/ttyACM0", baudrate=9600, timeout=1 )
while True:
    serial_port.write("Hey.")
    print(serial_port.read(1024))
