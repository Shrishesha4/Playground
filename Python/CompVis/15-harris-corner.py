import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt
img = cv.imread("sample.jpg")

gray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
dst = cv.cornerHarris(gray,2,3,0.04)
dst = cv.dilate(dst,None)
img[dst>0.01*dst.max()]=[0,0,255]

plt.imshow(img)
plt.show()