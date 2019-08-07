'''5回加工した画像を保存するよ'''

import os
import cv2
from PIL import Image
from PIL import ImageEnhance

IMG_PATH = "C:\\xampp\\htdocs\\php\\Horiuchi4J\\parent_image\\"
IMG_PATH2 = "C:\\xampp\\htdocs\\php\\Horiuchi4J\\processing_img\\"

def up_contrast():
    image1 =Image.open("C:\\xampp\\htdocs\\php\\Horiuchi4J\\processing_img\\Matsuzaki2PR_0.jpg")

    con6 = ImageEnhance.Color(image1)
    con6_image = con6.enhance(10.0 * 1)

    #画像出力
    con6_image.save("C:\\xampp\\htdocs\\php\\Horiuchi4J\\processing_img\\Matsuzaki2PR_1.jpg", quality=95)

def lighten_image():
    img =Image.open("C:\\xampp\\htdocs\\php\\Horiuchi4J\\processing_img\\Matsuzaki2PR_1.jpg")
    img_after = img.point(lambda x: x * (1.5 * 1))
    img_after.save("C:\\xampp\\htdocs\\php\\Horiuchi4J\\processing_img\\Matsuzaki2PR_1.jpg", quality=95)

def myface_cut():
    IMG = cv2.imread("C:\\xampp\\htdocs\\php\\Horiuchi4J\\parent_image\\Matsuzaki2PR_0.jpg",cv2.IMREAD_COLOR)

    #画像の出力
    cv2.imwrite("C:\\xampp\\htdocs\\php\\Horiuchi4J\\processing_img\\Matsuzaki2PR_1.jpg", IMG)
    #画像のコントラストと明度を上げる
    up_contrast()
    lighten_image()
    #gamma(count)

up_contrast()
lighten_image()