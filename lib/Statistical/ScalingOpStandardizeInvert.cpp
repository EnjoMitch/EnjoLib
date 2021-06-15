#include "ScalingOpStandardizeInvert.hpp"
#include "ScalingOpStandardize.hpp"
using namespace EnjoLib;
ScalingOpStandardizeInvert::ScalingOpStandardizeInvert(const ScalingOpStandardize & scaler)
: m_scaler(scaler)
{
}
double ScalingOpStandardizeInvert::operator()(const double standardized) const
{
    const double raw = standardized * m_scaler.GetRefStdDev() + m_scaler.GetRefMean();
    return raw;
}
