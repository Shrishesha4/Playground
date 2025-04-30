import cv2 as cv
import matplotlib.pyplot as plt
img = cv.imread("sample.jpg")
gray_img = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
plt.subplot(121),plt.imshow(img),plt.title('Color')
plt.xticks([]), plt.yticks([])
plt.subplot(122),plt.imshow(gray_img),plt.title('Gray')
plt.xticks([]), plt.yticks([])
plt.show()