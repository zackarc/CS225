#ifndef _RGBAPIXEL.H_
#define _RGBAPIXEL.H_
#include <cstdint>
using std::uint8_t;

class RGBAPixel{
public:
  RGBAPixel();
  RGBAPixel (uint8_t red, uint8_t green, uint8_t blue);
  uint8_t red;
  uint8_t green;
  uint8_t blue;
  uint8_t alpha;
};

#endif
