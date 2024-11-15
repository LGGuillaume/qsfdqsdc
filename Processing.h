#pragma once
#include "Image.h"

namespace processing
{
	void convertToGrey(Image& image);
	void convertToBinary(Image& image, const uint8& threshold = 122);
}