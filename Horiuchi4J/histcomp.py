import cv2
import matplotlib.pyplot as plt

def compare_by_hist(target_file):
    COMPARING_FILE = "\\output\\face_cut.jpg"
    IMG_DIR = "C:\\xampp\\htdocs\\php\\Horiuchi4J"
    IMG_SIZE = (200, 200)

    #比較するイメージファイルを読み込み、ヒストグラムを計算
    target_img_path = IMG_DIR + target_file
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
    #print(result * 100)
    return result * 100

target_file_arr = ["\\processing_img\\Matsuzaki1PR_0.jpg", "\\processing_img\\Matsuzaki1PR_1.jpg", "\\processing_img\\Matsuzaki2PR_0.jpg", "\\processing_img\\Matsuzaki2PR_1.jpg", "\\processing_img\\Matsuzaki3PR_0.jpg", "\\processing_img\\Matsuzaki3PR_1.jpg", "\\processing_img\\Matsuzaki4PR_0.jpg"]
result_arr = []
#target_file = "\\processing_img\\Matsuzaki1PR_0.jpg"
for target_file in target_file_arr:
    result_arr.append(compare_by_hist(target_file))

print(result_arr)
print(max(result_arr))