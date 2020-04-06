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
    for i in range(len(data)):
        dato = data[i]
        if dato < 128:
            if flag == 0:
                continue
            else:
                return False
        else:
            if flag > 0:
                b = dato & 192
                if b != 128:
                    return False
                else:
                    flag = flag - 1
            else:
                if dato >= 128 and dato < 192:
                    continue
                if dato >= 192 and dato < 224:
                    flag = 1
                if dato >= 224 and dato < 240:
                    flag = 2
                if dato >= 240:
                    flag = 3
    return (True)
