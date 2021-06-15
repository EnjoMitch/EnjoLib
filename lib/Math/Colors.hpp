#ifndef COLORS_H
#define COLORS_H

namespace EnjoLib
{

class Colors
{
public:
    typedef struct
    {
        double r,g,b;
    } COLOR;
    typedef struct
    {
        int r,g,b;
    } COLOR_256;
    COLOR GreyToRGB(double v,double vmin,double vmax) const;
    COLOR_256 To256(const COLOR & col) const;
    int To256(double col) const;
};

}
#endif // COLORS_H
