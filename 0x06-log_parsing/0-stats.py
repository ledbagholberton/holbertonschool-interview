#!/usr/bin/python3
"""Function log parsing
Change to include executable file
"""
import sys
import re


count = 0
total_size = 0
dict_error = {}
dict_list = ['200', '301', '400', '401', '403', '404', '405', '500']
parsed_data = []
try:
    for data in sys.stdin:
        parsed_data = re.split(r'[-+#\s*$ ]', data)
        size_parsed = len(parsed_data)
        if size_parsed > 2:
            count += 1
            size_file = int(parsed_data[size_parsed - 2])
            total_size += size_file
            error = parsed_data[size_parsed - 3]
            if error in dict_list:
                if error in dict_error:
                    dict_error[error] += 1
                else:
                    dict_error[error] = 1
        if count == 10:
            print("File size: {}".format(total_size))
            for k, v in sorted(dict_error.items()):
                print("{}: {}".format(k, v))
            count = 0
finally:
    print("File size: {}".format(total_size))
    for k, v in sorted(dict_error.items()):
        print("{}: {}".format(k, v))
