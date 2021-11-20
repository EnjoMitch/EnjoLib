#include <Statistical/Formatters.hpp>
#include <Util/StrColour.hpp>
#include <Ios/Osstream.hpp>
#include <Ios/IoManip.hpp>

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
