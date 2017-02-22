#include "image.h"
#include <iostream>
void Image::flipleft(){

	unsigned char temp;
	unsigned long width = this->width();
	unsigned long height = this->height();

	for (size_t yi = 0; yi < height; yi++){
		for (size_t xi = 0; xi < width/2; xi++){
			temp = (*this)(xi,yi)->red;
			(*this)(xi,yi)->red = (*this)(width-xi-1,yi)->red;
			(*this)(width-xi-1,yi)->red = temp;
			temp = (*this)(xi,yi)->green;
			(*this)(xi,yi)->green = (*this)(width-xi-1,yi)->green;
			(*this)(width-xi-1,yi)->green = temp;
			temp = (*this)(xi,yi)->blue;
			(*this)(xi,yi)->blue = (*this)(width-xi-1,yi)->blue;
			(*this)(width-xi-1,yi)->blue = temp;
		}
	}
}


void Image::adjustbrightness(int r, int g, int b){
	unsigned long width = this->width();
	unsigned long height = this->height();

	for (size_t xi = 0; xi < width; xi++){
		for (size_t yi = 0; yi < height; yi++){
			if ((*this)(xi,yi)->red + r > 255)
				(*this)(xi,yi)->red = 255;
				else if ((*this)(xi,yi)->red + r < 0)
					(*this)(xi,yi)->red = 0;
				else (*this)(xi,yi)->red += r;

			if ((*this)(xi,yi)->green + g > 255)
				(*this)(xi,yi)->green = 255;
				else if ((*this)(xi,yi)->green + g < 0)
					(*this)(xi,yi)->green = 0;
				else (*this)(xi,yi)->green += g;

			if ((*this)(xi,yi)->blue + b > 255)
				(*this)(xi,yi)->blue = 255;
			else if ((*this)(xi,yi)->blue + b < 0)
				(*this)(xi,yi)->blue = 0;
			else (*this)(xi,yi)->blue += b;
		}
	}
}


void Image::invertcolors()
{
	unsigned long width = this->width();
	unsigned long height = this->height();

	for (size_t xi = 0; xi < width; xi++){
		for (size_t yi = 0; yi < height; yi++){
			(*this)(xi,yi)->red = 255 - (*this)(xi,yi)->red;
			(*this)(xi,yi)->green = 255 - (*this)(xi,yi)->green;
			(*this)(xi,yi)->blue = 255 - (*this)(xi,yi)->blue;
		}
	}
}
