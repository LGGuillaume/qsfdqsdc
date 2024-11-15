#pragma once

#include <vector>
using uint8 = unsigned char;

struct Rgb
{
	Rgb(const uint8& r = 0, const uint8& g = 0, const uint8& b = 0);

	uint8 channels[3];
};

class Image
{
public:
	Image(const int& width = 0, const int& height = 0);

	void clear();
	void setSize(const int& width, const int& height);
	Rgb& getPixel(const int& row, const int& col);
	int getWidth() const;
	int getHeight() const;
	size_t getSize() const;
	Rgb& operator[](const size_t& index);

private:
	std::vector <Rgb> m_data;
	int m_width;
	int m_height;
};
