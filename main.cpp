#include "config.h"

#define CHANNEL_NUM 3

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

int main() {

    // Image
    const int image_width = 256;
    const int image_height = 256;

    u8* image = new u8[image_width * image_height * CHANNEL_NUM];
    int index = 0;

    for (int j = 0; j < image_height; ++j)
    {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i)
        {
            auto pixel_color = color(double(i) / (image_width), double(j) / (image_height), 0);       
            insert_color(image, index, pixel_color);
        }
    }
   
    generate_png("1", image_width, image_height, CHANNEL_NUM, image, image_width * CHANNEL_NUM);
    generate_jpg("1", image_width, image_height, image);

    std::clog << "\rDone.                 \n";

    delete[] image;
}