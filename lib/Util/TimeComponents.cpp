#include "TimeComponents.hpp"
#include "CharManipulations.hpp"
#include <Util/Osstream.hpp>

using namespace std;
using namespace EnjoLib;

TimeComponents::~TimeComponents(){}
TimeComponents::TimeComponents(double seconds)
: m_seconds(seconds)
, m_minutes(seconds / 60)
, m_hours(m_minutes / 60)
, m_str(MakeStr())
{
}

EnjoLib::Str TimeComponents::ToString() const
{
    return m_str;
}

EnjoLib::Str TimeComponents::MakeStr()
{
    CharManipulations cm;
    Osstream oss;
    const int leadingZeroes = 2;
    oss << cm.MakeLeadingZeroes(int(m_hours), leadingZeroes) << ":";
    oss << cm.MakeLeadingZeroes(int(m_minutes%60), leadingZeroes) << ":";
    oss << cm.MakeLeadingZeroes(int(int(m_seconds)%60), leadingZeroes) ;
    return oss.str();
}


