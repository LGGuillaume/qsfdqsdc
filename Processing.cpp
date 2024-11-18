#include "Processing.h"
#include <iostream>
#include <algorithm>

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
				channels = channels > threshold ? std::numeric_limits<uint8>::max() : 0;
		}

	}

	void medianFilter(Image& image, const int& filterSize)
	{
		const int width = image.getWidth();
		const int height = image.getHeight();
		Image result(width, height);
		const int offset = filterSize / 2;

		for (int col = offset; col < height - offset; ++col)
		{
			for (int row = offset; row < width - offset; ++row)
			{
				std::vector<uint8> nearR, nearG, nearB;
				nearR.reserve(filterSize * filterSize);
				nearG.reserve(filterSize * filterSize);
				nearB.reserve(filterSize * filterSize);

				for (int fcol = -offset; fcol <= offset; ++fcol)
				{
					for (int frow = -offset; frow <= offset; ++frow)
					{
						int ncol = col + fcol;
						int nrow = row + frow;

						if (ncol >= 0 && ncol < height && nrow >= 0 && nrow < width)
						{
							const auto& pixel = image.getPixel(ncol, nrow);
							nearB.push_back(pixel.channels[0]);
							nearG.push_back(pixel.channels[1]);
							nearR.push_back(pixel.channels[2]);
						}
					}
				}

				if (!nearR.empty() && !nearG.empty() && !nearB.empty())
				{
					std::sort(nearR.begin(), nearR.end());
					std::sort(nearG.begin(), nearG.end());
					std::sort(nearB.begin(), nearB.end());

					auto redMedian = nearR.size() / 2;
					auto blueMedian = nearB.size() / 2;
					auto greenMedian = nearG.size() / 2;
					image.getPixel(col, row).channels[0] = redMedian;
					image.getPixel(col, row).channels[1] = blueMedian;
					image.getPixel(col, row).channels[2] = greenMedian;
				}
				else
				{
					result.getPixel(col, row) = image.getPixel(col, row);
				}
			}
		}
		image = result;
	}
}
