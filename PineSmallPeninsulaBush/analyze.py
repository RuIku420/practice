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
    input_path = "imgまでのパス"
    output_path = " imgまでのパス（保存先のフォルダがinput_pathと一緒やん）"
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
    image1 =Image.open("gazou.jpgのパス")

    con6 = ImageEnhance.Color(image1)
    con6_image = con6.enhance(10.0 * count)

    #画像出力
    con6_image.save("gazou.jpgのパス", quality=95)

def lighten_image(count):
    img =Image.open("gazou.jpgのパス")
    img_after = img.point(lambda x: x * (1.5 * count))
    img_after.save("gazou.jpgのパス", quality=95)

#カスケード型分類器に使用する分類器のデータ（xmlファイル）を読み込み
def myface_cut():
    """gazou.jpgの画像部分を切り出す"""
    count = 0
    #5回までコントラストを上げる
    while count < 6:
        HAAR_FILE = 'haarcascade_frontalface_default.xmlのパス（cv2や各自ダウンロードしたもの）'
        CASCADE = cv2.CascadeClassifier(HAAR_FILE)

        #画像ファイルの読み込み
        IMAGE_PICTURE = 'gazou.jpgのパス'

        IMG = cv2.imread(IMAGE_PICTURE)

        #もともとの画像を一度だけ保存する
        if count == 0:
            #IMG = cv2.imread(IMAGE_PICTURE)
            cv2.imwrite('output/moto.jpgのパス', IMG)

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
            cv2.imwrite('output/face_cut.jpgのパス', face_cut)
            cv2.imwrite('output/face_rectangle.jpgのパス', IMG)
            break
        else:
            count += 1
            #画像のコントラストと明度を上げる
            up_contrast(count)
            lighten_image(count)
            #gamma(count)

extension_conversion()
myface_cut()
#compare_by_hist()