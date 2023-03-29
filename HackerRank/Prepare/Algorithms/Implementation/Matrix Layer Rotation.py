#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'matrixRotation' function below.
#
# The function accepts following parameters:
#  1. 2D_INTEGER_ARRAY matrix
#  2. INTEGER r
#

def get_layer_points(
    m: int,
    n: int,
    layer: int,
) -> list[tuple[int, int]]:
    points: list[tuple[int, int]] = []
    for row in range(layer, m - layer - 1):
        points.append((row, layer))
    for col in range(layer, n - layer - 1):
        points.append((m - layer - 1, col))
    for row in range(m - layer - 1, layer, -1):
        points.append((row, n - layer - 1))
    for col in range(n - layer - 1, layer, -1):
        points.append((layer, col))
    return points

def matrixRotation(matrix: list[list[int]], r: int):
    # Write your code here
    m = len(matrix)
    n = len(matrix[0])
    output = [line.copy() for line in matrix]
    for layer in range(min(m, n) // 2):
        dst = get_layer_points(m, n, layer)
        steps = r % len(dst)
        src = dst[-steps:] + dst[:-steps]
        for i in range(len(dst)):
            output[dst[i][0]][dst[i][1]] = matrix[src[i][0]][src[i][1]]
    for line in output:
        print(*line, sep=" ")
    

if __name__ == '__main__':
    first_multiple_input = input().rstrip().split()

    m = int(first_multiple_input[0])

    n = int(first_multiple_input[1])

    r = int(first_multiple_input[2])

    matrix = []

    for _ in range(m):
        matrix.append(list(map(int, input().rstrip().split())))

    matrixRotation(matrix, r)