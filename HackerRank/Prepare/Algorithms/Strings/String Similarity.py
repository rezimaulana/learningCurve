#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the stringSimilarity function below.
def stringSimilarity(a):
    ans =0
    ln = len(a)
    z = [0]*ln
    l,r = 0,0
    for i in range(1,ln):
        if (i <= r):
            z[i] = min (r-i+1, z[i-l])
        while(i +z[i] < ln and a[z[i]] == a[i+z[i]]):
            z[i] += 1
        if(i +z[i] -1 >r):
            l,r = i, i+z[i] -1
    return sum(z) + len(a)
            

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        s = input()

        result = stringSimilarity(s) 

        fptr.write(str(result) + '\n')

    fptr.close()