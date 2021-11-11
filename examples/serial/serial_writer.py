import serial
import time

#portName='/dev/cu.usbmodem1461301'
portName='COM1'
baudRate = 9600

ser = serial.Serial(portName,baudRate)
print("Opening port "+ ser.name)

if ser.is_open==True:
    print("Success!")
else:
    print("Unable to open port :(")

filename = "14_steps.csv"

file = open(filename)

#read the first list and discard in case of header
header = file.readline()

for line in file:
    #clear out endl characters
    line = line.replace('\r', '').replace('\n', '')

    #convert back to bytes because Python is weird
    accel_data = str.encode(line)

    #send the data down the serial port
    ser.write(accel_data)



print("Show's over. Close the port!")
ser.close()