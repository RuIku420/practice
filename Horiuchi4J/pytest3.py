""" This is face analyze program """


#オブジェクト指向で書いた方がいいの？
#変数が実質定数だったのでupper_caseにした。pylintを無視したいけどcv2でエラー吐かれるのできつい。
#画像をリサイズしてもいいかもしれない

#OpenCVのインポート
import os
import cv2
from PIL import Image
from PIL import ImageEnhance
import matplotlib.pyplot as plt


# pylint: disable=line-too-long

def extension_conversion():
    """imgディレクトリ下のgazou.pngをgazou.jpgにする"""
    input_path = "C:\\xampp\\htdocs\\php\\PineSmallPeninsulaBush\\img\\"
    output_path = "C:\\xampp\\htdocs\\php\\PineSmallPeninsulaBush\\img\\"
    files = os.listdir(input_path)
    count = 1

    for file in files:
        #file[-4:]にはimgディレクトリ下のファイルの拡張子が指定される
        if file[-4:] == ".png":
            input_im = Image.open(input_path + "gazou.png")
            rgb_im = input_im.convert('RGB')
            rgb_im.save(output_path + "gazou.jpg", quality=30)
            os.remove(input_path + "gazou.png")
            count = count + 1
            print("transaction finished" + str(count))

def up_contrast(count):
    image1 =Image.open("C:\\xampp\\htdocs\\php\\PineSmallPeninsulaBush\\img\\gazou.jpg")

    con6 = ImageEnhance.Color(image1)
    con6_image = con6.enhance(10.0 * count)

    #画像出力
    con6_image.save('C:\\xampp\\htdocs\\php\\PineSmallPeninsulaBush\\img\\gazou.jpg', quality=95)

def lighten_image(count):
    img =Image.open("C:\\xampp\\htdocs\\php\\PineSmallPeninsulaBush\\img\\gazou.jpg")
    img_after = img.point(lambda x: x * (1.5 * count))
    img_after.save('C:\\xampp\\htdocs\\php\\PineSmallPeninsulaBush\\img\\gazou.jpg', quality=95)

#カスケード型分類器に使用する分類器のデータ（xmlファイル）を読み込み
def myface_cut():
    """gazou.jpgの画像部分を切り出す"""
    count = 0
    #5回までコントラストを上げる
    while count < 6:
        HAAR_FILE = 'C:\\temp\\opencv-master\\opencv-master\\data\\haarcascades\\haarcascade_frontalface_default.xml'
        CASCADE = cv2.CascadeClassifier(HAAR_FILE)

        #画像ファイルの読み込み
        IMAGE_PICTURE = 'C:\\xampp\\htdocs\\php\\PineSmallPeninsulaBush\\img\\gazou.jpg'

        IMG = cv2.imread(IMAGE_PICTURE)

        #グレースケールに変換する
        IMG_G = cv2.imread(IMAGE_PICTURE, 0)

        #カスケード型分類器を使用して画像ファイルから顔部分を検出する
        FACE = CASCADE.detectMultiScale(IMG_G)

        #顔の座標を表示する、nullであれば別の文を表示する
        print(FACE)

        #顔部分を切り取る
        for x, y, w, h in FACE:
            face_cut = IMG[y:y+h, x:x+w]

        #白枠で顔を囲む
        for x, y, w, h in FACE:
            cv2.rectangle(IMG, (x, y), (x+w, y+h), (255, 255, 255), 2)

        if FACE != ():
            #画像の出力
            cv2.imwrite('C:\\xampp\\htdocs\\php\\PineSmallPeninsulaBush\\output\\face_cut.jpg', face_cut)
            cv2.imwrite('C:\\xampp\\htdocs\\php\\PineSmallPeninsulaBush\\output\\face_rectangle.jpg', IMG)
            break
        else:
            count += 1
            #画像のコントラストと明度を上げる
            up_contrast(count)
            lighten_image(count)
            #gamma(count)

#ここはexecで別ファイルで動かそう。$optを別々にするため
'''
def compare_by_hist():
    #認識できなかった時の処理書こうぜ
    TARGET_FILE = "\\parent_image\\MatsuzakiFC_1.jpg"
    COMPARING_FILE = "\\output\\face_cut.jpg"
    IMG_DIR = "C:\\xampp\\htdocs\\php\\PineSmallPeninsulaBush"
    IMG_SIZE = (200, 200)

    #比較するイメージファイルを読み込み、ヒストグラムを計算
    target_img_path = IMG_DIR + TARGET_FILE
    target_img = cv2.imread(target_img_path)
    target_img = cv2.resize(target_img, IMG_SIZE)
    target_hist = cv2.calcHist([target_img], [0], None, [256], [0, 256])

    #比較されるイメージファイルを読み込み、ヒストグラムを計算
    comparing_img_path = IMG_DIR + COMPARING_FILE
    comparing_img = cv2.imread(comparing_img_path)
    comparing_img = cv2.resize(comparing_img, IMG_SIZE)
    comparing_hist = cv2.calcHist([comparing_img], [0], None, [256], [0, 256])

    #ヒストグラムを比較する
    result = cv2.compareHist(target_hist, comparing_hist, 0)
    print(result * 100)
'''

extension_conversion()
myface_cut()
#compare_by_hist()