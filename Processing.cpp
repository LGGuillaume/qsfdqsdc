#include "Processing.h"

namespace processing
{
	void convertToGrey(Image& image)
	{
		for (auto i = 0; i < image.getSize(); ++i)
		{
			int average = 0;
			for (auto& channels : image[i].channels)
				average += channels;

			average /= 3;

			for (auto& channels : image[i].channels)
				channels = static_cast<uint8>(average);
		}
	}
	void convertToBinary(Image& image, const uint8& threshold)
	{
		for (auto i = 0; i < image.getSize(); ++i)
		{
			for (auto& channels : image[i].channels)
				channels = channels > threshold ? std::numeric_limits<uint8>::max(): 0;
		}

	}
}