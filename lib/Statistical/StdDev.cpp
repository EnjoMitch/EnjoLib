#include "StdDev.hpp"

using namespace EnjoLib;

StdDev::StdDev(double stdDev)
: m_stdDev(stdDev)
{
}

double StdDev::GetValue() const
{
    return m_stdDev;
}

double StdDev::GetVariance() const
{
    return m_stdDev * m_stdDev;
}
