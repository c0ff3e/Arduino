#!/usr/bin/python
import serial, time, os
ser = serial.Serial('/dev/ttyACM0',9600)

filename = '/var/log/syslog'
filename2 = '/var/log/auth.log'

file1 = open(filename,'r')
file = open(filename2,'r')

st_results = os.stat(filename)
st_size = st_results[6]
file1.seek(st_size)
st_results2 = os.stat(filename2)
st_size2 = st_results2[6]
file.seek(st_size2)


while 1:
#    if "file" == file:
#      file = file1
#    else:
#      file = file2
    where = file.tell()
    line = file.readline()
    if not line:
        time.sleep(1)
        file.seek(where)
    else:
        if "whoopsie" in line:
            ser.write('2')
            print line,
        elif "Failed password" in line:
            ser.write('3')
            print line,

