'''5回加工した画像を保存するよ'''

import os
import cv2
from PIL import Image
from PIL import ImageEnhance

#なぜか使ってない
IMG_PATH = "加工したい画像のパス"
IMG_PATH2 = "processing_img/加工後の画像のパス"

def up_contrast():
    image1 =Image.open("IMG_PATH")

    con6 = ImageEnhance.Color(image1)
    con6_image = con6.enhance(10.0 * 1)

    #画像出力
    con6_image.save("IMG_PATH2", quality=95)

def lighten_image():
    img =Image.open("IMG_PATH2")
    img_after = img.point(lambda x: x * (1.5 * 1))
    img_after.save("IMG_PATH2", quality=95)

def myface_cut():
    IMG = cv2.imread("IMG_PATH",cv2.IMREAD_COLOR)

    #画像の出力
    cv2.imwrite("IMG_PATH2", IMG)
    #画像のコントラストと明度を上げる
    up_contrast()
    lighten_image()
    #gamma(count)

up_contrast()
lighten_image()