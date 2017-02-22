#include <algorithm>
#include <iostream>

#include "rgbapixel.h"
#include "png.h"

using namespace std;

// This function rotates the PNG graph by 180 degrees
PNG rotate(PNG original)
{
	PNG rotated(original.width(), original.height());
	unsigned long xi,yi;
	for (xi = 0; xi < original.width(); xi++){
		for (yi = 0; yi < original.height(); yi++){
			rotated(xi,yi)->red = original(original.width()-xi-1, original.height()-yi-1)->red;
			rotated(xi,yi)->green = original(original.width()-xi-1, original.height()-yi-1)->green;
			rotated(xi,yi)->blue = original(original.width()-xi-1, original.height()-yi-1)->blue;
			rotated(xi,yi)->alpha = original(original.width()-xi-1, original.height()-yi-1)->alpha;
		}
	}
	return rotated;
}

int main() {
	PNG original("in.png");
	PNG rotated = rotate(original);
	rotated.writeToFile("out.png");
	return 0;
}
