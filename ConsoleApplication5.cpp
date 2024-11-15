#include "Bitmap.h"
#include "Processing.h"


int main()
{
	Bitmap bmp;

	bmp.load("ffVII.bmp");

	auto image = bmp.getImage();

	processing::convertToGrey(image);
	processing::convertToBinary(image);

	bmp.save("ffviiBiS.bmp");

	return 0;
}
