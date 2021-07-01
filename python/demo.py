import os
import numpy as np


# SAMPLE_STRS = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j']
MAX_STRING_LENGTH = 100
MIN_STRINGLENGTH = 80
MAX_CASE_NUMBER = 1000
MAX_STR_KIND = 4

# generate strings
strList = []


# io
testCasePath = "testcase/stringPairs.txt"
with open(testCasePath, 'w') as f:
    # np.random.randint(i,j)   [i,j)
    for i in range(MAX_CASE_NUMBER):
        strLen1 = np.random.randint(MIN_STRINGLENGTH, MAX_STRING_LENGTH)
        strLen2 = np.random.randint(MIN_STRINGLENGTH, MAX_STRING_LENGTH)
        s1 = ""
        s2 = ""
        for j in range(strLen1):
            c = chr(ord('a')+np.random.randint(MAX_STR_KIND))
            s1 += c
        for j in range(strLen2):
            c = chr(ord('a')+np.random.randint(MAX_STR_KIND))
            s2 += c
        #strList.append([s1, s2])
        print(s1, s2)
        f.write(s1)
        f.write(' ')
        f.write(s2)
        f.write('\n')
f.close()
