#!/usr/bin/python3
"""
Main file for testing
"""

minOperations = __import__('0-minoperations').minOperations

n = 4
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

n = 12
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

n = 9
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

n = 'uno'
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

n = 37.5
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

n = 2000
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

n = 42
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))
