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

### #1

```python
import numpy as np
import imgplot

figure = imgplot.figure()

data_rect = np.array(...)
axis = imgplot.image(data_rect)
figure.add(axis, x=0, y=0, width=1, height=1)

window = imgplot.window(figure, size=(400, 200), title="Lena")
window.show()

while True:
    if window.closed():
        exit()

    ... some computation

    data = np.array(...)
    axis.update(data)
```

![screenshot from 2018-07-01 22-11-58](https://user-images.githubusercontent.com/15250418/42134687-ce1a90bc-7d7b-11e8-93cb-3614703d7383.png)

### #2

```python
axis = imgplot.image(data_square)
figure.add(axis, x=0, y=0, width=1, height=1)

window = imgplot.window(figure, size=(400, 400), title="Lena")
```

![screenshot from 2018-07-01 22-13-56](https://user-images.githubusercontent.com/15250418/42134729-5af54716-7d7c-11e8-97b3-5db463a9069c.png)


### #3

```python
axis1 = imgplot.image(data_rect)
figure.add(axis1, x=0, y=0, width=1, height=0.5)

axis2 = imgplot.image(data_rect)
figure.add(axis2, x=0, y=0.5, width=1, height=0.5)
```

![screenshot from 2018-07-01 21-58-14](https://user-images.githubusercontent.com/15250418/42134638-d91ff0fc-7d7a-11e8-8d44-27404e0407b0.png)

### #4

```python
axis1 = imgplot.image(data_rect)
figure.add(axis1, x=0, y=0, width=1, height=1.0 / 3.0)

axis2 = imgplot.image(data_rect)
figure.add(axis2, x=0, y=1.0 / 3.0, width=1, height=1.0 / 3.0)

axis3 = imgplot.image(data_rect)
figure.add(axis3, x=0, y=2.0 / 3.0, width=1, height=1.0 / 3.0)

window = imgplot.window(figure, size=(400, 600), title="Lena")
```

![screenshot from 2018-07-01 22-17-51](https://user-images.githubusercontent.com/15250418/42134762-9d7f978a-7d7c-11e8-8076-090ff94288f7.png)

### #5

```python
axis1 = imgplot.image(data_rect)
figure.add(axis1, x=0, y=0, width=1, height=0.5)

axis2 = imgplot.image(data_square)
figure.add(axis2, x=0, y=0.5, width=0.5, height=0.5)

axis3 = imgplot.image(data_square)
figure.add(axis3, x=0.5, y=0.5, width=0.5, height=0.5)

window = imgplot.window(figure, size=(400, 400), title="Lena")
```

![screenshot from 2018-07-01 22-23-36](https://user-images.githubusercontent.com/15250418/42134816-79d70e0c-7d7d-11e8-856f-16328cc3fef3.png)

### #6

```python
axis1 = imgplot.image(data_rect)
figure.add(axis1, x=0, y=0.0, width=2.0 / 3.0, height=1)

axis2 = imgplot.image(data_square)
figure.add(axis2, x=2.0 / 3.0, y=0, width=1.0 / 3.0, height=1)

window = imgplot.window(figure, size=(600, 200), title="Lena")
```

![screenshot from 2018-07-01 22-26-14](https://user-images.githubusercontent.com/15250418/42134843-d28d525e-7d7d-11e8-8721-292b6742e179.png)

