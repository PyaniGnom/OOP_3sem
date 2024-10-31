#include <iostream>
#include <cstdint>
#include "BMP.h"

int main() {
    int32_t width { 7 };
    int32_t height { 7 };

    std::array<std::array<uint8_t, 3>, 7> colors = {{
        {255, 0, 139},
        {255, 0, 0},
        {255, 170, 66},
        {0, 255, 0},
        {0, 255, 255},
        {0, 165, 255},
        {0, 0, 255}
    }};

    BMP bmp(width, height, false);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            bmp.bmp_data[y * width * 3 + x * 3 + 0] = colors[y][0];
            bmp.bmp_data[y * width * 3 + x * 3 + 1] = colors[y][1];
            bmp.bmp_data[y * width * 3 + x * 3 + 2] = colors[y][2];
        }
    }

    bmp.write("../OMEGALOL.bmp");

    return 0;
}
