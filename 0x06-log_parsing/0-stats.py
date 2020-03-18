#!/usr/bin/python
import sys
import re

count = 0
total_size = 0
total_200 = 0
total_401 = 0
total_403 = 0
total_404 = 0
total_405 = 0
total_500 = 0
try:
    for data in sys.stdin:
        parsed_data = re.split(r'[-+#\s*$ ]', data)
        size_parsed = len(parsed_data)
        count += 1
        size_file = int(parsed_data[size_parsed - 2])
        total_size += size_file
        error = int(parsed_data[size_parsed - 3])
        if error == 200:
            total_200 += 1
        elif error == 401:
            total_401 += 1
        elif error == 403:
            total_403 += 1
        elif error == 404:
            total_404 += 1
        elif error == 405:
            total_405 += 1
        elif error == 500:
            total_500 += 1
        if count == 10:
            print("File size: {}".format(total_size))
            print("200: {}".format(total_200))
            print("401: {}".format(total_401))
            print("403: {}".format(total_403))
            print("404: {}".format(total_404))
            print("405: {}".format(total_405))
            print("500: {}".format(total_500))
            count = 0
except KeyboardInterrupt:
    print("File size: {}".format(total_size))
    print("200: {}".format(total_200))
    print("401: {}".format(total_401))
    print("403: {}".format(total_403))
    print("404: {}".format(total_404))
    print("405: {}".format(total_405))
    print("500: {}".format(total_500))
