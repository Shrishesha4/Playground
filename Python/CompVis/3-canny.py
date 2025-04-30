import cv2 as cv
import matplotlib.pyplot as plt
img = cv.imread("sample.jpg")
gray_img = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
edges = cv.Canny(gray_img, 100, 200)
plt.subplot(121),plt.imshow(img),plt.title('Original')
plt.xticks([]), plt.yticks([])
plt.subplot(122),plt.imshow(edges),plt.title('Edges')
plt.xticks([]), plt.yticks([])
plt.show()