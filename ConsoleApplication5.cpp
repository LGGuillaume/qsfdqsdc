#include "Bitmap.h"
#include "Processing.h"
#include <iostream>

int main()
{
    Bitmap bmp;

    bmp.load("C:\\Users\\guill\\source\\repos\\qsfdqsdc\\ffVII.bmp");
 
    //processing::convertToGrey(bmp.getImage()); 
    ////processing::convertToBinary(bmp.getImage());

    //bmp.save("C:\\Users\\guill\\source\\repos\\qsfdqsdc\\imageBiS.bmp");


    //bmp.load("C:\\Users\\guill\\source\\repos\\qsfdqsdc\\imageBiS.bmp");

    processing::medianFilter(bmp.getImage(), 3);

    bmp.save("C:\\Users\\guill\\source\\repos\\qsfdqsdc\\ffviiBiS2.bmp");


    return 0;
}
