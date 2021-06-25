

var tempPath = "/work/pic/"
fileList=[]
for (var i = 1; i <= 140; i++) {
    img_name = i.toString() + ".png"
    img_name = tempPath + img_name
    fileList.push(img_name)
    console.log(img_name)
}