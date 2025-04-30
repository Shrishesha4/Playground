import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

def analyze_histogram(img_path):
  img = cv.imread("sample.jpg")
  color_channels = ('b', 'g', 'r')
  for i, color in enumerate(color_channels):
    hist = cv.calcHist([img], [i], None, [256], [0, 256])
    plt.plot(hist, color=color, label=f"{color.upper()} Channel")
    plt.xlim([0, 256])
  plt.title("Color Histogram Analysis")
  plt.xlabel("Pixel Intensity")
  plt.ylabel("Frequency")
  plt.legend()
  plt.show()

analyze_histogram("sample.jpg")