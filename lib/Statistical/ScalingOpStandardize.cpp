#include "ScalingOpStandardize.hpp"
#include "Assertions.hpp"
#include "Statistical.hpp"
#include "../Util/VecD.hpp"

#include "../Util/CharManipulations.hpp"
#include "../Util/Tokenizer.hpp"


#include <STD/String.hpp>

using namespace EnjoLib;
// Used for reconstruction
ScalingOpStandardize::ScalingOpStandardize(double refMean, double refStdDev)
: m_refMean(refMean)
, m_refStdDev(refStdDev)
{
    Assertions::IsNonZero(m_refStdDev, "ScalingOpStandardize::ScalingOpStandardize - zero stdDev");
}
ScalingOpStandardize::ScalingOpStandardize(const EnjoLib::Str & str)
{
    //const VecStr & lines = Tokenizer().GetLines(fileName);
    //const EnjoLib::Str & str = lines.at(0);
    const VecStr & meanStd = Tokenizer().Tokenize(str);
    m_refMean   = CharManipulations().ToDouble(meanStd.at(0));
    m_refStdDev = CharManipulations().ToDouble(meanStd.at(1));
}
ScalingOpStandardize::ScalingOpStandardize(const VecD & refVec)
{
    Assertions::NonEmpty(refVec,   "ScalingOpStandardize::ScalingOpStandardize::constr() - refVec");
    m_refMean = refVec.Mean();
    m_refStdDev = Statistical().StandardDeviation(refVec);
    Assertions::IsNonZero(m_refStdDev, "ScalingOpStandardize::ScalingOpStandardize::constr() - zero stdDev");
}
double ScalingOpStandardize::operator()(const double inVal) const
{
    Assertions::IsNonZero(m_refStdDev, "ScalingOpStandardize::ScalingOpStandardize::op() - zero stdDev");
    const double standardized = (inVal - m_refMean) / m_refStdDev;
    return standardized;
}
EnjoLib::Str ScalingOpStandardize::ToStr() const
{
    //CharManipulations cman;
    const EnjoLib::Str str = std::to_string(m_refMean) + " " + std::to_string(m_refStdDev);
    //cout << m_refMean << ", " << m_refStdDev << ", " << str << endl;
    return str;
}
void ScalingOpStandardize::SetRefMean(double mean)
{
    m_refMean = mean;
}
void ScalingOpStandardize::SetRefStdDev(double stdDev)
{
    m_refStdDev = stdDev;
}
