#include "Colors.hpp"
#include "GeneralMath.hpp"

using namespace EnjoLib;

/*
   Return a RGB colour value given a scalar v in the range [vmin,vmax]
   In this case each colour component ranges from 0 (no contribution) to
   1 (fully saturated), modifications for other ranges is trivial.
   The colour is clipped at the end of the scales if v is outside
   the range [vmin,vmax]

   (C) Paul Bourke  http://paulbourke.net/texture_colour/colourspace/
*/

Colors::COLOR Colors::GreyToRGB(double v,double vmin,double vmax) const
{
   COLOR c = {1.0,1.0,1.0}; // white
   double dv;

   if (v < vmin)
      v = vmin;
   if (v > vmax)
      v = vmax;
   dv = vmax - vmin;

   if (v < (vmin + 0.25 * dv)) {
      c.r = 0;
      c.g = 4 * (v - vmin) / dv;
   } else if (v < (vmin + 0.5 * dv)) {
      c.r = 0;
      c.b = 1 + 4 * (vmin + 0.25 * dv - v) / dv;
   } else if (v < (vmin + 0.75 * dv)) {
      c.r = 4 * (v - vmin - 0.5 * dv) / dv;
      c.b = 0;
   } else {
      c.g = 1 + 4 * (vmin + 0.75 * dv - v) / dv;
      c.b = 0;
   }

   return(c);
}

Colors::COLOR_256 Colors::To256(const COLOR & col) const
{
    COLOR_256 ret = {0, 0, 0};
    ret.r = To256(col.r);
    ret.g = To256(col.g);
    ret.b = To256(col.b);
    return ret;
}

int Colors::To256(double col) const
{
    const int maxVal = 255;
    int res = GeneralMath().round(col * maxVal);
    if (res > maxVal)
        res = maxVal;
    return res;
}
