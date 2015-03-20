import serial
import time
import sys
import struct

print("Arcturus Incubator and lights controller python driver")

# check the number of input parameters
if len(sys.argv) < 2:
  print("You need to call python incubator-driver.py UV_ON | UV_OFF | MONITOR")
  sys.exit()

# configure and open the serial port
serial_port = serial.Serial( port="/dev/ttyACM0", baudrate=9600, timeout=1)
serial_port.setDTR(True)
time.sleep(0.5)
serial_port.flushInput()
serial_port.setDTR()
time.sleep(2.5)

if sys.argv[1] == "UV_ON":
  print("Turning on the UV light ...")
  serial_port.write("1")
  i = 0
  while i < 10:
    serial_port.write("1")
    time.sleep(0.5)
    i += 1
  sys.exit()

if sys.argv[1] == "UV_OFF":
  print("Turning off the UV light ...")
  serial_port.write("0")
  i = 0
  while i < 10:
    serial_port.write("0")
    time.sleep(0.5)
    i += 1
  sys.exit()

if sys.argv[1] == "MONITOR":
  while True:
    sys.stdout.write(serial_port.readline())