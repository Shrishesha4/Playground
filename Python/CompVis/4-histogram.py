import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt
img = cv.imread("sample.jpg")
gray_img = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
equalized_img = cv.equalizeHist(gray_img)
plt.subplot(121),plt.imshow(img),plt.title('Color')
plt.xticks([]), plt.yticks([])
plt.subplot(122),plt.imshow(equalized_img),plt.title('Equalized')
plt.xticks([]), plt.yticks([])
plt.show()