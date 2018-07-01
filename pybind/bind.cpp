#include "../core/data/image.h"
#include "../core/figure.h"
#include "../core/view/image.h"
#include "../core/window.h"
#include <pybind11/pybind11.h>
namespace py = pybind11;
using namespace imgplot;

PYBIND11_MODULE(imgplot, module)
{
    py::class_<data::ImageData>(module, "image")
        .def(py::init<int, int, int>(), py::arg("width"), py::arg("height"), py::arg("num_channels"))
        .def(py::init<py::array_t<GLubyte>, int, int, int>(), py::arg("data"), py::arg("width"), py::arg("height"), py::arg("num_channels"))
        .def("resize", &data::ImageData::resize)
        .def("update", &data::ImageData::update);

    py::class_<Figure>(module, "figure")
        .def(py::init<>())
        .def("add", &Figure::add, py::arg("data"), py::arg("x"), py::arg("y"), py::arg("width"), py::arg("height"));

    py::class_<Window>(module, "window")
        .def(py::init<Figure*, py::tuple>(), py::arg("figure"), py::arg("size"))
        .def("closed", &Window::closed)
        .def("show", &Window::show);
}