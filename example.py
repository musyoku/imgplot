import time

import numpy as np
from PIL import Image

import imgplot

figure = imgplot.Figure()

lena_rectangle = np.array(
    Image.open("lena_rectangle.jpg", "r").convert("RGB"))
height, width, channels = lena_rectangle.shape
axis_rectangle = imgplot.ImageData(width, height, channels)
axis_rectangle.update(np.uint8(lena_rectangle))
figure.add(axis_rectangle, x=0, y=0, width=1, height=0.5)

lena_square = np.array(Image.open("lena_square.jpg", "r"))
height, width, channels = lena_square.shape
axis_square = imgplot.ImageData(width, height, channels)
axis_square.update(lena_square)
figure.add(axis_square, x=0.25, y=0.5, width=0.5, height=0.5)

window = imgplot.Window(figure, size=(500, 500))
window.show()

while True:
    if window.closed():
        exit()

    # lena_square = np.uint8(lena_square * 0.9)
    # axis_square.update(lena_square)
    time.sleep(1)
