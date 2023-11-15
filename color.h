#pragma once

#include "vec3.h"

#include <iostream>

using color = vec3;

void insert_color(uint8_t* image, int& index, color& pixel_color) {
    image[index++] = static_cast<int>(pixel_color.r() * 255.99);
    image[index++] = static_cast<int>(pixel_color.g() * 255.99);
    image[index++] = static_cast<int>(pixel_color.b() * 255.99);
}
