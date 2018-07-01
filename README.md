# :construction: Work in Progress :construction:
# imgplot

imgplot is a non-blocking image viewer for Python 3.

# Requirements

- C++14 (gcc-6)
- OpenGL 4
- Python 3

# Installation

**GLFW**

```
sudo apt install libglfw3-dev
```
**pybind11**

```
pip3 install pybind11 --user
```
**imgplot**

```
make
```

# Usage

## Basic usage

```
import numpy as np
import imgplot

figure = imgplot.figure()

data = np.array(...)
height, width, channels = data.shape
axis = imgplot.image(data, width, height, channels)
figure.add(axis, x=0, y=0, width=1, height=1)

window = imgplot.window(figure, size=(500, 500), title="Title")
window.show()

while True:
    if window.closed():
        exit()

    ... some computation

    data = np.array(...)
    axis.update(data)
```

## #1
