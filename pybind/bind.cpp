#include "../core/data/image.h"
#include "../core/figure.h"
#include "../core/view/image.h"
#include "../core/window.h"
#include <pybind11/pybind11.h>
namespace py = pybind11;
using namespace imgplot;

PYBIND11_MODULE(imgplot, module)
{
    py::class_<data::ImageData>(module, "ImageData")
        .def(py::init<int, int, int>(), py::arg("height"), py::arg("width"), py::arg("num_channels"))
        .def("resize", &data::ImageData::resize)
        .def("update", &data::ImageData::update);

    py::class_<Figure>(module, "Figure")
        .def(py::init<>())
        .def("add", (void (Figure::*)(data::ImageData*, double, double, double, double)) &Figure::add);

    py::class_<Window>(module, "Window")
        .def(py::init<Figure*, py::tuple>())
        .def("closed", &Window::closed)
        .def("show", &Window::show);
}