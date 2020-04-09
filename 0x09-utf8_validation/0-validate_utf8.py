#!/usr/bin/python3
""" Function UTF-8
Return: True if data is a valid UTF-8 encoding, else return False
A character in UTF-8 can be 1 to 4 bytes long
The data set can contain multiple characters
The data will be represented by a list of integers
Each integer represents 1 byte of data, therefore you only need
to handle the 8 least significant bits of each integer
"""


def validUTF8(data):
    """ Funtion UTF-8 """
    flag = 0
    for i in data:
        dato = i & 0xff
        if flag == 0:
            if dato >= 192 and dato < 224:
                flag = 1
            if dato >= 224 and dato < 240:
                flag = 2
            if dato >= 240 and dato < 248:
                flag = 3
            if dato >= 128 and dato < 192:
                return False
        else:
            if not (dato >= 128 and dato < 192):
                return False
            flag = flag-1
    if flag != 0:
        return(False)
    return(True)
