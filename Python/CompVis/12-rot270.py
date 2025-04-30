import cv2 as cv
import matplotlib.pyplot as plt
img = cv.imread("sample.jpg")
rotated_img = cv.rotate(img, cv.ROTATE_90_COUNTERCLOCKWISE)
plt.subplot(121),plt.imshow(img),plt.title('Original')
plt.xticks([]), plt.yticks([])
plt.subplot(122),plt.imshow(rotated_img),plt.title('Rotated 270')
plt.xticks([]), plt.yticks([])
plt.show()