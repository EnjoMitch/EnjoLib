#ifndef SCALINGOPSTANDARDIZE_H
#define SCALINGOPSTANDARDIZE_H

#include <Util/Str.hpp>

namespace EnjoLib
{
class VecD;

class ScalingOpStandardize
{
public:
    ScalingOpStandardize(const VecD & refVec);
    ScalingOpStandardize(double refMean = 0, double refStdDev = 1);
    ScalingOpStandardize(const EnjoLib::Str & str);
    double operator()(const double inVal) const;
    double GetRefMean() const { return m_refMean; }
    double GetRefStdDev() const { return m_refStdDev; }
    void SetRefMean(double mean);
    void SetRefStdDev(double stdDev);
    EnjoLib::Str ToStr() const;

private:
    double m_refMean;
    double m_refStdDev;
};
}

#endif // SCALINGOPSTANDARDIZE_H
