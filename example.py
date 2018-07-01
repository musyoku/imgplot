import time

import numpy as np
from PIL import Image

import imgplot

figure = imgplot.figure()

lena_rectangle = np.array(
    Image.open("lena_rectangle.jpg", "r").convert("RGB"))
height, width, channels = lena_rectangle.shape
axis_rectangle = imgplot.image(lena_rectangle, width, height, channels)
figure.add(axis_rectangle, x=0, y=0, width=1, height=0.5)

lena_square = np.array(Image.open("lena_square.jpg", "r"))
height, width, channels = lena_square.shape
axis_square = imgplot.image(width, height, channels)
axis_square.update(lena_square)
figure.add(axis_square, x=0.25, y=0.5, width=0.5, height=0.5)

window = imgplot.window(figure, size=(500, 500))
window.show()

while True:
    if window.closed():
        exit()

    lena_rectangle = np.uint8(lena_rectangle * 0.9)
    axis_rectangle.update(lena_rectangle)
    lena_square = np.uint8(lena_square * 0.9)
    axis_square.update(lena_square)
    time.sleep(1)
