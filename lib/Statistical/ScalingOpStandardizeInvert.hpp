#ifndef SCALINGOPSTANDARDIZEINVERT_HPP
#define SCALINGOPSTANDARDIZEINVERT_HPP

namespace EnjoLib
{
class ScalingOpStandardize;
class ScalingOpStandardizeInvert
{
    public:
        ScalingOpStandardizeInvert(const ScalingOpStandardize & scaler);
        double operator()(const double standardized) const;
    private:
        const ScalingOpStandardize & m_scaler;
};
}

#endif // SCALINGOPSTANDARDIZEINVERT_HPP
