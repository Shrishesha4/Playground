import cv2 as cv
import matplotlib.pyplot as plt
img = cv.imread("sample.jpg")
gray_img = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
dilated_img = cv.dilate(gray_img, None, iterations=1)
plt.subplot(121),plt.imshow(img),plt.title('Original')
plt.xticks([]), plt.yticks([])
plt.subplot(122),plt.imshow(dilated_img),plt.title('Dilated')
plt.xticks([]), plt.yticks([])
plt.show()