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
    """flag = 1 si es uno de un byte"""
    for i in range(len(data)):
        dato = data[i]
        if dato < 128:
            if flag == 0:
                continue
            else:
                return False
        else:
            if flag > 0:
                dato = (dato & 0b11000000) ^ (0b01111111)
                if dato != 0:
                    return False
                else:
                    flag = flag - 1
            else:
                a = int(bin(dato), 2)
                flag = flag + 1
                while a & 0b1000000 != 0:
                    a = a << 1
                    flag = flag + 1
    return (True)
