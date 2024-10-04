from picamera2 import Picamera2
import time
import cv2
import sys
import numpy as np
import gc
import threading


def recv_from_pipe(fr): 
    line = fr.readline()

    if len(line)>0 and line[0]=='c':
        return True
    return False

def send_to_pipe(fw,val):
    #print(('send: ',val,fw))
    #fw.write(val)
    print(val,file=fw)
    fw.flush()
    # fw.close()

def getColor():
    ret_col='r'

    LOW_COLOR1 = np.array([0, 50, 80]) # 各最小値を指定
    HIGH_COLOR1 = np.array([8, 255, 255]) # 各最大値を指定
    LOW_COLOR2 = np.array([171, 50, 80]) # 各最小値を指定
    HIGH_COLOR2 = np.array([179, 255, 255]) # 各最大値を指定

    LOW_COLOR3 = np.array([90, 70, 140]) # 各最小値を指定
    HIGH_COLOR3 = np.array([150, 255, 255]) # 各最大値を指定

    print("capture!")
    im = pc2.capture_array()
    cv2.imwrite("orgine.jpg",im)

    # im = cv2.cvtColor(im, cv2.COLOR_BGR2RGB)
    im = cv2.resize(im,None,fx=0.25,fy=0.25)
    y,x = im.shape[0],im.shape[1]
    cv2.imwrite("org.jpg",im)

    im = trim(im,(0,100),(x,y//2-30)) # サークルの影響を排除するため上半分で判定
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

    area_r,_ = contourarea(mask_r)
    area_b,_ = contourarea(mask_b)

    print(("R",area_r,"B",area_b))
    if area_r==0 and area_b==0:
        ret_col='x'
    elif area_r>area_b: 
        ret_col='r'
    else:
        ret_col='b'

    cv2.imwrite("img.jpg",im)
    cv2.imwrite("r_mask.jpg",mask_r)
    cv2.imwrite("b_mask.jpg",mask_b)
    print("write ok")
    gc.collect()

    return ret_col

def getMarker():
    LOW_COLOR3 = np.array([90, 70, 140]) # 各最小値を指定
    HIGH_COLOR3 = np.array([150, 255, 255]) # 各最大値を指定

    print("get marker!")
    im = pc2.capture_array()
    # im = cv2.cvtColor(im, cv2.COLOR_BGR2RGB)
    im = cv2.resize(im,None,fx=0.25,fy=0.25)
    y,x = im.shape[0],im.shape[1]
    cv2.imwrite("marker_org.jpg",im)

    im = trim(im,(0,y//2),(x,y//2-y//4)) #ボトルの影響を排除するため下半分で判定
    hsv = cv2.cvtColor(im, cv2.COLOR_BGR2HSV)

    row ,col = im.shape[0]//2,im.shape[1]//2

    mask_b = cv2.inRange(hsv, LOW_COLOR3, HIGH_COLOR3) # マスクを作成

    area_b, cont = contourarea(mask_b,200)

    rect = cv2.boundingRect(cont)
    print(("marker",area_b,rect))
    
    left = rect[0]
    right = rect[0]+rect[2]
    if area_b==0:
        adjust=0
    elif x//2-left>right-x//2:
        adjust = left-x//2
    else:
        adjust = right-x//2
    
    cv2.imwrite("marker_img.jpg",im)
    cv2.imwrite("marker_b_mask.jpg",mask_b)
    print("write ok")
    gc.collect()

    return adjust

def getMarker2(im):
    LOW_COLOR3 = np.array([90, 70, 140]) # 各最小値を指定
    HIGH_COLOR3 = np.array([150, 255, 255]) # 各最大値を指定

    print("get marker!")
    y,x = im.shape[0],im.shape[1]
    cv2.imwrite("maker/marker_org.jpg",im)

    im = trim(im,(0,y//4),(x,y//2-y//4)) #ボトルの影響を排除するため下半分で判定
    hsv = cv2.cvtColor(im, cv2.COLOR_BGR2HSV)

    row ,col = im.shape[0]//2,im.shape[1]//2

    mask_b = cv2.inRange(hsv, LOW_COLOR3, HIGH_COLOR3) # マスクを作成

    area_b, cont = contourarea(mask_b,200)

    rect = cv2.boundingRect(cont)
    if(len(rect)==0): 
        print("Maker None")
        return 0
    print(("marker",area_b,rect))
    
    left = rect[0]
    right = rect[0]+rect[2]

    center_pos=(left+right)/2
    
    cv2.imwrite("maker/marker_img.jpg",im)
    cv2.imwrite("maker/marker_b_mask.jpg",mask_b)
    print("write ok")

    return int(center_pos*100/im.shape[1])

def circle_center():
    global img_cnt
    img = pc2.capture_array()
    img = cv2.resize(img,None,fx=0.25,fy=0.25)

    #debug 
    # img = cv2.imread("circle_1820/circle_org4.jpg")

    y,x = img.shape[0],img.shape[1]
    cv2.imwrite("circle/circle_org%d.jpg"%img_cnt,img)

    c=getMarker2(img)
    if c!=0:
        return c

    img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    img = trim(img,(int(x*0.1),int(y*0.4)),(x-int(x*0.2),y//8)) #ボトルの影響を排除するため下半分で判定
    cv2.imwrite("circle/circle_trim%d.jpg"%img_cnt,img)

    #影を消せる？
    ksize = 51
    blur = cv2.blur(img, (ksize, ksize))
    rij = img/blur
    index_1 = np.where(rij >= 0.98)
    index_0 = np.where(rij < 0.98)
    rij[index_0] = 0
    rij[index_1] = 1
    img = rij*255
    cv2.imwrite("circle/circle_trim_blur%d.jpg"%img_cnt,img)

    #以下のシャープ化フィルタも試してみる
    # kernel = np.array([[0,-1,0], [-1,5,-1], [0,-1,0]], np.float32)
    kernel = np.array([[-1,-1,-1], [-1,9,-1], [-1,-1,-1]], np.float32) 

    img = cv2.filter2D(img,-1,kernel)

    h,w = img.shape[0],img.shape[1]

    img = trim(img,(10,10),(w-30,h-10)) #フィルタの影響を消す

    h,w = img.shape[0],img.shape[1]
    print(h,w)

    center = w//2
    left = center-int(w*0.2)
    right = center+int(w*0.2)

    # サンプル取得
    pt1 = img[h//2, left-5]
    pt2 = img[h//2, right+5]
    # pt1 = img[10, left-10]
    # pt2 = img[10, left+10]
    print("samplle",pt1,pt2)
    # background = (int(pt1)+int(pt2))/2
    background=200
    cv2.rectangle(img, (left,0 ), (right, h), (background, background, background), thickness=-1)
    bin_img1 = cv2.inRange(img, 0, background*.8) # マスクを作成
    center = contourarea_circle(bin_img1)
    print(center)

    cv2.imwrite('circle/circle_org_seg%d.jpg'%img_cnt,bin_img1)

    img_cnt+=1

    return center

def contourarea_circle(mask):
    #物体検出
    contours, hierarchy = cv2.findContours(mask, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
    # print(contours)
    # 矩形検出された数（デフォルトで0を指定）
    detect_count = 0
    max_area=0
    max_contour=None
    left_pos=mask.shape[1]
    right_pos=0
    for i in range(0, len(contours)):

        # 輪郭の領域を計算
        area = cv2.contourArea(contours[i])
        if area < 10 : #ノイズ
            continue
        rect = cv2.boundingRect(contours[i])
        print(rect)
        if left_pos>rect[0]:
            left_pos=rect[0]
        if right_pos<rect[0]+rect[2]:
            right_pos=rect[0]+rect[2]
        detect_count +=1
    center_pos=(left_pos+right_pos)/2

    print("left,center,right ",left_pos/mask.shape[1],center_pos/mask.shape[1],right_pos/mask.shape[1])
    return int(center_pos*100/mask.shape[1])

#トリミング 左上xy座標とサイズ
def trim(img,top_left,bottom_right):
    return img[top_left[1] : bottom_right[1]+top_left[1] , top_left[0]: bottom_right[0]+top_left[0]]

def contourarea(mask,min_area=5000):
        #物体検出
    contours, hierarchy = cv2.findContours(mask, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
    # 矩形検出された数（デフォルトで0を指定）
    detect_count = 0
    max_area=0
    max_contour=None
    for i in range(0, len(contours)):

        # 輪郭の領域を計算
        area = cv2.contourArea(contours[i])
        if area < min_area : # サークルが微妙に入っても除外
            continue
        if max_area<area:
            max_area=area
            max_contour=contours[i]
        detect_count +=1

    print("detected ",max_area)
    return max_area,max_contour

def checkmk_thred():
    global mode
    # global fr,fw
    if mode=='skip':
        getMarker()
        return

    if mode!='r':
        fw = open('/home/pi/RasPike-ART/sdk/workspace/cam2run_b', 'w',encoding='ascii')
    else:
        print("READ ONLY MODE")

    fr = open('/home/pi/RasPike-ART/sdk/workspace/run2cam_b', 'r',encoding='ascii')

    print("pipe open OK.")
    while True:
        if recv_from_pipe(fr):
            ret = getMarker()
            if mode!='r':
                send_to_pipe(fw,ret)
                print("send ok")

def getimage_thred():
    global mode
    
    # global fr,fw
    if mode=='skip':
        getColor()
        return

    if mode!='r':
        fw = open('/home/pi/RasPike/sdk/workspace/cam2run', 'w',encoding='ascii')
    else:
        print("READ ONLY MODE")

    fr = open('/home/pi/RasPike/sdk/workspace/run2cam', 'r',encoding='ascii')

    print("pipe open OK.")
    while True:
        if recv_from_pipe(fr):
            ret = getColor()
            if mode!='r':
                send_to_pipe(fw,ret)
                print("send ok")

def checkcircle_thred():
    global mode
    global img_cnt
    img_cnt=0
    # global fr,fw
    if mode=='skip':
        print("skip_")
        circle_center()
        return

    if mode!='r':
        fw = open('/home/pi/RasPike/sdk/workspace/cam2run_b', 'w',encoding='ascii')
    else:
        print("READ ONLY MODE")

    fr = open('/home/pi/RasPike/sdk/workspace/run2cam_b', 'r',encoding='ascii')

    print("pipe open OK.")
    while True:
        if recv_from_pipe(fr):
            ret = circle_center()
            if mode!='r':
                send_to_pipe(fw,ret)
                print("send ok")


def main():
    global pc2
    global mode
    args = sys.argv
    
    if len(args)>1:
        mode = args[1]
    else: 
        mode =''

    pc2 = Picamera2()
    fullReso = pc2.camera_properties['PixelArraySize']

    pc2.configure(pc2.create_preview_configuration(main={"format": 'XRGB8888', "size": fullReso}, raw={ "size" : fullReso }))
    pc2.start()
    time.sleep( 1 )

    th1 = threading.Thread(target=getimage_thred)
    th1.start()
    # th2 = threading.Thread(target=checkmk_thred)
    # th2.start()
    th3 = threading.Thread(target=checkcircle_thred)
    th3.start()

main()