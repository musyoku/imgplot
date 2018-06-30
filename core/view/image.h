#pragma once
#include "../data/image.h"
#include "../renderer/image.h"
#include <gl3w/gl3w.h>
#include <glfw/glfw3.h>
#include <memory>
#include <pybind11/numpy.h>

namespace imgplot {
namespace view {
    class ImageView {
    private:
        data::ImageData* _data;
        std::unique_ptr<renderer::ImageRenderer> _renderer;
        double _x;
        double _y;
        double _width;
        double _height;
        void bind_data();

    public:
        ImageView(data::ImageData* data, double x, double y, double width, double height);
        double x();
        double y();
        double width();
        double height();
        void render(double aspect_ratio);
    };
}
}