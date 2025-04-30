import cv2 as cv
import matplotlib.pyplot as plt
import numpy as np
img = cv.imread("sample.jpg")

st = np.array([[0,0], [img.shape[1] - 1, 0], [0, img.shape[0] - 1]]).astype(np.float32)
dt = np.array([[0, img.shape[1]*0.33], [img.shape[1]*0.85, img.shape[0]*0.25], [img.shape[1]*0.15, img.shape[0]*0.7]]).astype(np.float32)

transform = cv.getAffineTransform(st, dt)
transformed_img = cv.warpAffine(img, transform, (img.shape[1], img.shape[0]))

plt.subplot(121),plt.imshow(img),plt.title('Original')
plt.xticks([]), plt.yticks([])
plt.subplot(122),plt.imshow(transformed_img),plt.title('Rotated')
plt.xticks([]), plt.yticks([])
plt.show()