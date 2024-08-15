from picamera2 import Picamera2
import time
import cv2
import sys
import numpy as np
import gc



def recv_from_pipe():
    global fr
 
    line = fr.readline()

    if len(line)>0 and line[0]=='c':
        return True
    return False
def send_to_pipe(val):
    global fw
    #print(('send: ',val,fw))
    #fw.write(val)
    print(val,file=fw)
    fw.flush()
    # fw.close()

def getColor():
    ret_col='r'

    LOW_COLOR1 = np.array([0, 50, 0]) # 各最小値を指定
    HIGH_COLOR1 = np.array([8, 255, 255]) # 各最大値を指定
    LOW_COLOR2 = np.array([171, 50, 0]) # 各最小値を指定
    HIGH_COLOR2 = np.array([179, 255, 255]) # 各最大値を指定

    LOW_COLOR3 = np.array([100, 50, 0]) # 各最小値を指定
    HIGH_COLOR3 = np.array([140, 255, 255]) # 各最大値を指定

    print("capture!")
    im = pc2.capture_array()
    # im = cv2.cvtColor(im, cv2.COLOR_BGR2RGB)
    im = cv2.resize(im,None,fx=0.25,fy=0.25)
    y,x = im.shape[0],im.shape[1]
    cv2.imwrite("org.jpg",im)

    im = trim(im,(0,0),(x,y//2-30)) # サークルの影響を排除するため上半分で判定
    hsv = cv2.cvtColor(im, cv2.COLOR_BGR2HSV)

    row ,col = im.shape[0]//2,im.shape[1]//2

    # print(im.shape)
    # val = im[row,col]
    # print(val)
    # val = hsv[row ,col]
    # print(val)

    bin_img1 = cv2.inRange(hsv, LOW_COLOR1, HIGH_COLOR1) # マスクを作成
    bin_img2 = cv2.inRange(hsv, LOW_COLOR2, HIGH_COLOR2)
    mask_r = bin_img1 + bin_img2 # 必要ならマスクを足し合わせる
    mask_b = cv2.inRange(hsv, LOW_COLOR3, HIGH_COLOR3) # マスクを作成

    masked_img = cv2.bitwise_and(im,im, mask= mask_r) # 元画像から特定の色を抽出

    area_r = contourarea(mask_r)
    area_b = contourarea(mask_b)

    print(("R",area_r,"B",area_b))
    if area_r>area_b: 
        ret_col='r'
    else:
        ret_col='b'

    cv2.imwrite("img.jpg",im)
    cv2.imwrite("r_mask.jpg",mask_r)
    cv2.imwrite("b_mask.jpg",mask_b)
    print("write ok")
    gc.collect()

    return ret_col

def trim(img,top_left,bottom_right):
    return img[top_left[1] : bottom_right[1]-top_left[1] , top_left[0]: bottom_right[0]-top_left[0]]

def contourarea(mask):
        #物体検出
    contours, hierarchy = cv2.findContours(mask, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
    # 矩形検出された数（デフォルトで0を指定）
    detect_count = 0
    max_area=0
    for i in range(0, len(contours)):

        # 輪郭の領域を計算
        area = cv2.contourArea(contours[i])
        if area < 5000: # サークルが微妙に入っても除外
            continue
        if max_area<area:
            max_area=area
        detect_count +=1

    print("detected ",max_area)
    return max_area

def main():
    global fr,fw,pc2
    args = sys.argv
    
    if len(args)>1:
        mode = args[1]
    else: 
        mode =''

    pc2 = Picamera2()
    pc2.configure(pc2.create_preview_configuration(main={"format": 'XRGB8888', "size": (3280, 2464)}))
    pc2.start()
    time.sleep( 1 )
    if mode=='skip':
        getColor()
        return


    if mode!='r':
        fw = open('/home/pi/RasPike-ART/sdk/workspace/cam2run', 'w',encoding='ascii')
    else:
        print("READ ONLY MODE")

    fr = open('/home/pi/RasPike-ART/sdk/workspace/run2cam', 'r',encoding='ascii')

    # fw = open('/home/pi/RasPike-ART/sdk/workspace/cam2run', 'w', encoding="ascii")
    print("pipe open OK.")
    while True:
        if recv_from_pipe():
            ret = getColor()
            if mode!='r':
                send_to_pipe(ret)
                print("send ok")

main()