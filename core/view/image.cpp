#include "image.h"
#include "../opengl.h"
#include <glm/glm.hpp>
#include <iostream>

namespace imgplot {
namespace view {
    ImageView::ImageView(data::ImageData* data, double x, double y, double width, double height)
    {
        _x = x;
        _y = y;
        _width = width;
        _height = height;
        _data = data;
        _renderer = std::make_unique<renderer::ImageRenderer>();
    }
    double ImageView::x()
    {
        return _x;
    }
    double ImageView::y()
    {
        return _y;
    }
    double ImageView::width()
    {
        return _width;
    }
    double ImageView::height()
    {
        return _height;
    }
    void ImageView::bind_data()
    {
        _renderer->set_data(_data->raw(), _data->height(), _data->width());
    }
    void ImageView::render(double aspect_ratio)
    {
        if (_data->updated()) {
            bind_data();
        }
        _renderer->render(aspect_ratio);
    }
}
}
