#pragma once

#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION

// Third party libs
#include"stb_image_write.h"
#include<string>


void generate_png(std::string name, int width, int height, int channels, uint8_t* image, int stride_byte) {
	std::string file = "result/png/" + name + ".png";
	stbi_write_png(file.c_str(), width, height, channels, image, stride_byte);
}

void generate_jpg(std::string name, int width, int height, uint8_t* image) {
	std::string file = "result/jpg/" + name + ".jpg";
	stbi_write_jpg(file.c_str(), width, height, 3, image, 100);
}