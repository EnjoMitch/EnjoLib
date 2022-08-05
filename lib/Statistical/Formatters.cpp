#include <Statistical/Formatters.hpp>
#include <Statistical/Statistical.hpp>
#include <Ios/IoManip.hpp>
#include <Ios/Osstream.hpp>
#include <Math/GeneralMath.hpp>
#include <Util/StrColour.hpp>
#include <Visual/AsciiMisc.hpp>

using namespace EnjoLib;

Formatters::Formatters(int precision)
: m_precision(precision)
{
}
Formatters::~Formatters(){}


EnjoLib::Str Formatters::FormatVar(const double var, bool color, int prec) const
{
    if (prec < 0)
    {
        prec = m_precision;
    }
    const StrColour col;
    Osstream oss;
    oss << IoManip::SetPrecision(oss, prec);
    oss << IoManip::Fixed(oss);

    if (var > 0)
    {
        oss << " "; // adjust for a missing minus
    }
    if (color)
    {
        oss << col.GenNorm(var);
    }
    else
    {
        oss << var;
    }
    return oss.str();
}

EnjoLib::Str Formatters::VecLabel() const
{
    return "Mean Median ± StDev%  │ StDev bar";
}

EnjoLib::Str Formatters::FormatVec(const VecD & vec, bool color, double multiplier) const
{
    const StrColour col;
    const Statistical stat;
    const GMat gmat;

    const double mean   = stat.Mean(vec) * multiplier;
    const double median = stat.Median(vec) * multiplier;
    const double stdDev = stat.StandardDeviation(vec) * multiplier;
    const double stdDevPerc = stdDev / median * 100;
    const double stdDevPercAbs = gmat.Fabs(stdDevPerc);

    Osstream oss;
    oss << IoManip::SetPrecision(oss, 3);
    oss << IoManip::Fixed(oss);

    //oss << "| ";

    oss << FormatVar(mean, color) << " ";
    oss << FormatVar(median, color);
    oss << IoManip::SetPrecision(oss, 1);
    Str density = "░";
    density = "";
    /*
    if (stdDevPercAbs > 33)
    {
        density = "▒";
    }
    if (stdDevPercAbs > 50)
    {
        density = "▓"; make 10 bars
    }
    */
    oss << " ± " << density << "" << stdDevPercAbs << "%\t " << AsciiMisc().GenBars10(stdDevPercAbs);
    return oss.Str();
}
