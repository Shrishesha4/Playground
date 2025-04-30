import cv2 as cv
import matplotlib.pyplot as plt
img = cv.imread("sample.jpg")
big_img = cv.resize(img, (0, 0), fx=2, fy=2, interpolation=cv.INTER_LINEAR)
small_img = cv.resize(img, (0, 0), fx=0.5, fy=0.5, interpolation=cv.INTER_AREA)
plt.imshow(big_img),plt.title('Big')
plt.xticks([]), plt.yticks([])
plt.subplot(122),plt.imshow(small_img),plt.title('Small')
plt.xticks([]), plt.yticks([])
plt.show()
