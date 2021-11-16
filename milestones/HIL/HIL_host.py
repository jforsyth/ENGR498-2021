import serial
import time

# portName='/dev/cu.usbmodem1461301'
portName = 'COM3'
baudRate = 9600

ser = serial.Serial(portName, baudRate)
print("Opening port " + ser.name)

if ser.is_open == True:
    print("Success!")
else:
    print("Unable to open port :(")

filename = "14_steps.csv"

file = open(filename)

# read the first list and discard in case of header
header = file.readline()

# use a flag to loop until we're done
done = False

# while not done....
while done is False:
    # wait for '!' from Serial port
    bytes = ser.readline()

    # decode bytes into string
    received = bytes.decode('utf-8')
    received = received.replace('\r', '').replace('\n', '')

    if '!' in received is False:
        print("Invalid request received. Continue to wait.")
        continue

    #clear the input buffer in case we've been spammed
    ser.reset_input_buffer()

    # pull from file
    line = file.readline()

    # check if we've hit the end of file
    if line == '':
        print("End of file. We're done here.")
        done = True
        continue

    # clear out endl characters
    line = line.replace('\r', '').replace('\n', '')

    # echo what we're doing
    print("Received request to Send. Sending: " + line)

    # convert back to bytes because Python is weird
    accel_data = str.encode(line)

    # send the data down the serial port
    ser.write(accel_data)

    #wait until a response from the board
    bytes = ser.readline()

    # decode bytes into string
    response = bytes.decode('utf-8')
    response = response.replace('\r', '').replace('\n', '')

    print("Target reported: "+response)

print("Show's over. Close the port!")
ser.close()
