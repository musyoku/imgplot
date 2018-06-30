#pragma once
#include "data/image.h"
#include <vector>

namespace imgplot {
class Figure {
public:
    std::vector<std::tuple<data::ImageData*, double, double, double, double>> _images;
    void add(data::ImageData* data, double x, double y, double width, double height);
};
}