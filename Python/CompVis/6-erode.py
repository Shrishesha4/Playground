import cv2 as cv
import matplotlib.pyplot as plt
img = cv.imread("sample.jpg")
gray_img = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
eroded_img = cv.erode(gray_img, None, iterations=1)
plt.subplot(121),plt.imshow(img),plt.title('Original')
plt.xticks([]), plt.yticks([])
plt.subplot(122),plt.imshow(eroded_img),plt.title('Eroded')
plt.xticks([]), plt.yticks([])
plt.show()
