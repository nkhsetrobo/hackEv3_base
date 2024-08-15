from picamera2 import Picamera2
import time
import cv2
import sys
import numpy as np

img = cv2.imread("img.jpg")
hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

row ,col = img.shape[0]//2,img.shape[1]//2

print(img.shape)
val = img[row,col]
print(val)
val = hsv[row ,col]
print(val)

cv2.rectangle(img,(col-5,row-5),(col+10,row+10),(255, 0, 0))

cv2.imwrite("img2.jpg",img)
