import os
import random
# import numpy as np


SAMPLE_STRS = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j']
MAX_STRING_LENGTH = 100
MAX_CASE_NUMBER = 1000


a = ''.join(random.sample(SAMPLE_STRS, 5))

# generate strings
strList = []


# io
testCasePath = "/work/tool/algo/testcase/stringPairs.txt"
with open(testCasePath, 'w') as f:
    # np.random.randint(i,j)   [i,j)
    for i in range(MAX_CASE_NUMBER):
        strLen1 = random.randint(1, MAX_STRING_LENGTH)
        strLen2 = random.randint(1, MAX_STRING_LENGTH)
        s1 = ""
        s2 = ""
        for j in range(strLen1):
            c = chr(ord('a')+random.randint(26))
            s1 += c
        for j in range(strLen2):
            c = chr(ord('a')+random.randint(26))
            s2 += c
        #strList.append([s1, s2])
        print(s1, s2)
        f.write(s1)
        f.write(' ')
        f.write(s2)
        f.write('\n')
f.close()
