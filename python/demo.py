import os
import numpy as np

MAX_STRING_LENGTH = 100
MAX_CASE_NUMBER = 1000

# generate strings
strList = []


# io
testCasePath = "/Users/messi/Documents/MacBookAir/work/code/cpp/algo/testcase/stringPairs.txt"
with open(testCasePath, 'w') as f:
    # np.random.randint(i,j)   [i,j)
    for i in range(MAX_CASE_NUMBER):
        strLen1 = np.random.randint(1, MAX_STRING_LENGTH)
        strLen2 = np.random.randint(1, MAX_STRING_LENGTH)
        s1 = ""
        s2 = ""
        for j in range(strLen1):
            c = chr(ord('a')+np.random.randint(26))
            s1 += c
        for j in range(strLen2):
            c = chr(ord('a')+np.random.randint(26))
            s2 += c
        #strList.append([s1, s2])
        print(s1, s2)
        f.write(s1)
        f.write(' ')
        f.write(s2)
        f.write('\n')
f.close()
