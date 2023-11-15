#pragma once

#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include"stb_image_write.h"
#include<string>


class Image {
private:
	int width;
	int height;
	int channel;

	uint8_t* image;
public:
	
	Image(int width, int height, int channel) : width(width), height(height), channel(channel) {
		image = new uint8_t[width * height * channel];
	}

	~Image() {
		delete[] image;
	}

	int get_width() const {
		return width;
	}

	int get_height() const {
		return height;
	}

	int get_channel() const {
		return channel;
	}

	void generate_as_png(std::string name) {
		int stride_byte = width * channel;
		std::string file = "result/png/" + name + ".png";
		stbi_write_png(file.c_str(), width, height, channel, image, stride_byte);
	}

	void generate_as_jpg(std::string name) {
		std::string file = "result/jpg/" + name + ".jpg";
		stbi_write_jpg(file.c_str(), width, height, 3, image, 100);
	}

	void insert_color(int& index, color& pixel_color) {
		image[index++] = static_cast<int>(pixel_color.r() * 255.99);
		image[index++] = static_cast<int>(pixel_color.g() * 255.99);
		image[index++] = static_cast<int>(pixel_color.b() * 255.99);
	}

};
