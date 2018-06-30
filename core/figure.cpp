#include "figure.h"

namespace imgplot {
void Figure::add(data::ImageData* data, double x, double y, double width, double height)
{
    _images.emplace_back(data, x, y, width, height);
}
}