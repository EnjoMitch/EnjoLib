#include "SplineLin.hpp"
#include "GeneralMath.hpp"

#include <STD/VectorCpp.hpp>
#include <utility>
#include <Util/Osstream.hpp>
#include <Util/Except.hpp>

using namespace std;
using namespace EnjoLib;

SplineLin::~SplineLin(){}
SplineLin::SplineLin(const EnjoLib::VecD& in)
: spline(new std::vector<std::pair<EnjoLib::Point, EnjoLib::Point> >)
{
    for (int i = 1; i < int(in.size()); ++i)
    {
        //const double sz = in.size();
        const double x1 = (i-1);
        const double x2 = (i-0);
        const double y1 = in.at(i-1);
        const double y2 = in.at(i-0);
        spline.GetRW().push_back(make_pair(Point(x1, y1), Point(x2, y2)));
    }
}

double SplineLin::Interpol(double x) const
{
    GeneralMath gm;
    for (unsigned i = 0; i < spline.Get().size(); ++i)
    {
        const pair<Point, Point> & segment = spline.Get().at(i);
        if (segment.first.x <= x && x <= segment.second.x)
        {
            return gm.LinearInterpol(x, segment.first, segment.second);
        }
    }
    // Oops. Didn't find yet. Perhaps it's a rounding error
    const pair<Point, Point> & segmentLast = spline.Get().at(spline.Get().size()-1);
    int xRounded = gm.round(x);
    if (xRounded == segmentLast.second.x)
    {
        return gm.LinearInterpol(x, segmentLast.first, segmentLast.second);
    }
    Osstream oss;
    oss << "x = " << x << " not in spline of max arg = " << spline.Get().at(spline.Get().size()-1).second.x;
    throw EnjoLib::ExceptInvalidArg(oss.str());
}

int SplineLin::GetSplineSize() const
{
    return spline.Get().size() + 1;
}

EnjoLib::VecD SplineLin::Scale(int outSize) const
{
    const int inSize = GetSplineSize();
    if (outSize > inSize)
        return ScaleUp(outSize);
    else
        return ScaleDown(outSize);
}

EnjoLib::VecD SplineLin::ScaleUp(int outSize) const
{
    const int inSize = GetSplineSize();
    if (outSize < inSize)
    {
        Osstream oss;
        oss << "chosen size = " << outSize << " is smaller than inp size = " << inSize;
        throw EnjoLib::ExceptInvalidArg(oss.str());
    }
    const double scaleFactor = (inSize-1) / double(outSize-1);
    EnjoLib::VecD out(outSize);
    for (int i = 0; i < int(outSize); ++i)
    {
        const double x = i * scaleFactor;
        //cout << "i = " << i << ", xscaled = " << x << endl;
        double y = Interpol(x);
        out.atw(i) = y;
    }
    return out;
}

EnjoLib::VecD SplineLin::ScaleDown(int outSize) const
{
    const int inSize = GetSplineSize();
    if (outSize > inSize)
    {
        Osstream oss;
        oss << "chosen size = " << outSize << " is greater than inp size = " << inSize;
        throw EnjoLib::ExceptInvalidArg(oss.str());
    }
    const double scaleFactor = (inSize-1) / double(outSize-1);
    EnjoLib::VecD out(outSize);
    for (int i = 0; i < int(outSize); ++i)
    {
        const double x = i * scaleFactor;
        //cout << "i = " << i << ", xscaled = " << x << endl;
        double y = Interpol(x);
        out.atw(i) = y;
    }
    return out;
}



