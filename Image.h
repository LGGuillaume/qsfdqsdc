#pragma once

#include <vector>
using uint8 = unsigned char;

struct Point
{
	Point(float x_, float y_) : x(x_), y(y_) {}
	float x;
	float y;
};

Point operator-(const Point& op1, const Point& op2);
Point operator+(const Point& op1, const Point& op2);
Point operator/(const Point& op1, float op2);
Point operator*(const Point& op1, float op2);

struct Rgb
{
	static constexpr int channels_count = 3;
	Rgb(const uint8& r = 0, const uint8& g = 0, const uint8& b = 0);
	uint8 channels[channels_count];
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
	bool isInside(const int& row, const int& col) const;
	const Rgb& getPixel(const int& row, const int& col) const;
	void setPixel(const int& row, const int& col, const Rgb& color);

private:
	std::vector <Rgb> m_data;
	int m_width;
	int m_height;
};

struct machin
{

};