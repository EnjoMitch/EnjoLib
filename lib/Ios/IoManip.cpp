#include <Ios/IoManip.hpp>
#include <Ios/Ostream.hpp>

#include <STD/Ostream.hpp>
#include <STD/Iomanip.hpp>

using namespace EnjoLib;
IoManip::IoManip(){}
IoManip::~IoManip(){}

Ostream & IoManip::SetPrecision(Ostream & ostr, int prec)
{
    ostr.OStr() << std::setprecision(prec);
    return ostr;
}

Ostream & IoManip::SetW(Ostream & ostr, int width)
{
    ostr.OStr() << std::setw(width);
    return ostr;
}

Ostream & IoManip::SetFill(Ostream & ostr, char toFill)
{
    ostr.OStr() << std::setfill(toFill);
    return ostr;
}

Ostream & IoManip::Fixed(Ostream & ostr)
{
    std::fixed(ostr.OStr());
    return ostr;
}

Ostream & IoManip::Scientific(Ostream & ostr)
{
    std::scientific(ostr.OStr());
    return ostr;
}
