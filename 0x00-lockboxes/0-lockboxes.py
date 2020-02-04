#!/usr/bin/python3
"""function for challenge boxes
"""
import numpy as np


def canUnlockAll(boxes):
    """function canUnlockAll"""
    size = len(boxes)
    my_boxes = np.zeros(size)
    my_boxes[0] = 1
    for i in range(len(boxes)):
        for j in boxes[i]:
            if j is not i:
                my_boxes[j] = 1
    if my_boxes.prod() == 1:
        return (True)
    else:
        return (False)
