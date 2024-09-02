import cv2

def main():
    img = cv2.imread('xxx_marker_img.jpg')
    img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)


    h,w = img.shape[0],img.shape[1]
    print(h,w)

    center = w//2
    left = center-int(w*0.2)
    width = center + int(w*0.2)

    # サンプル取得
    pt1 = img[h//2, left-5]
    pt2 = img[h//2, left+5]
    print(pt1,pt2)
    background = (int(pt1)+int(pt2))/2
    cv2.rectangle(img, (left,0 ), (width, h), (255, 255, 255), thickness=-1)
    bin_img1 = cv2.inRange(img, 0, background*.8) # マスクを作成
    center = contourarea_circle(bin_img1)
    print(center)

    cv2.imwrite('tmp.jpg',img)
    cv2.imwrite('tmp_seg.jpg',bin_img1)

def contourarea_circle(mask):
        #物体検出
    contours, hierarchy = cv2.findContours(mask, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
    print(contours)
    # 矩形検出された数（デフォルトで0を指定）
    detect_count = 0
    max_area=0
    max_contour=None
    left_pos=mask.shape[1]
    right_pos=0
    for i in range(0, len(contours)):

        # 輪郭の領域を計算
        area = cv2.contourArea(contours[i])
        if area < 100 : #ノイズ
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
    return center_pos/mask.shape[1]


main()