#include "AxisRescale.hpp"
#include <Util/Except.hpp>

using namespace EnjoLib;

AxisRescale::AxisRescale(const PairD & axisStartEndIn,
                         const PairD & axisStartEndOut)
{
    m_axisInMin = axisStartEndIn.first;
    m_axisInMax = axisStartEndIn.second;
    m_axisOutMin = axisStartEndOut.first;
    m_axisOutMax = axisStartEndOut.second;

    if (m_axisInMin > m_axisInMax)
        std::swap(m_axisInMin, m_axisInMax);

    if (m_axisOutMin > m_axisOutMax)
        std::swap(m_axisOutMin, m_axisOutMax);

    m_lenIn  = m_axisInMax -  m_axisInMin;
    m_lenOut = m_axisOutMax - m_axisOutMin;
}

double AxisRescale::operator()(const double pointOnInputScale) const
{
    if (! IsValid())
    {
        throw ExceptInvalidArg("AxisRescale::Rescale(): Length of one of the inputs is 0! Use IsValid() first.");
    }
    const double shiftedFromInTo0 = pointOnInputScale - m_axisInMin;    // Shift input to 0
    const double unit = shiftedFromInTo0 / m_lenIn;                     // Make a unit vector
    const double spreadToOut = unit * m_lenOut;                         // Spread to output's length
    const double shiftedToOut = spreadToOut + m_axisOutMin;             // Shift to output's minimal value
    return shiftedToOut;
}

bool AxisRescale::IsValid() const
{
    //return m_lenIn * m_lenOut > 0;
    return m_lenIn > 0;
}
