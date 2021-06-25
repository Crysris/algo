# coding=utf8
from PIL import Image
import os
import random


def saveAsPic(image, path, name):
    img


def search(src, target):
    g = os.walk(src)
    for path, dir_list, file_list in g:
        for f in file_list:
            file_name = os.path.join(path, f)
            print("file", file_name)
        # for d in dir_list:
        #     dir_name = os.path.join(path, d)
        #     print("dir", dir_name)


# search("/work/pic/2","/work/pic")
src = "/work/pic/2"
target = "/work/pic"

for i in range(1, 100001):
    srcName = str(random.randint(1, 100))+'.png'
    srcName = os.path.join(src, srcName)
    with Image.open(srcName) as im:
        targetName = os.path.join(target, str(i)+'.png')
        im.save(targetName, "png")
        print('save successfully !', targetName)
