#include "ProgressMonitHigh.hpp"
#include "ProgressMonit.hpp"
#include "../Math/GeneralMath.hpp"
#include "../Util/TimeComponents.hpp"

#include <Ios/Cout.hpp>
#include <Ios/Osstream.hpp>
#include <Visual/AsciiMisc.hpp>

using namespace std;
using namespace EnjoLib;

ProgressMonitHigh::ProgressMonitHigh(int numBars) : m_numBars(numBars) {}
ProgressMonitHigh::~ProgressMonitHigh(){}

void ProgressMonitHigh::PrintProgressBarTime(size_t i, size_t sz, const EnjoLib::Str & idd, bool onPercentChange) const
{
    ProgressMonit pm(m_numBars);
    int percentDone = pm.GetPercentDoneInt(i, sz);
    /// TODO: Make it a pattern and extract it.
    if (! onPercentChange || percentDone != m_prevPercentDone)
    {
        Osstream oss;
        double sec = m_timer.GetElapsedSeconds();
        double leftTime = GeneralMath().round(pm.GetTimeLeft(i, sz, sec));
        TimeComponents timeLeftFormatted(leftTime);
        TimeComponents timePassedFormatted(sec);

        oss << idd << ": i = " << i << " / " << sz << " = " << percentDone << "%" << " " << pm.GetProgressBar(i, sz)
        << " ETA = " << timeLeftFormatted.ToString() << ", ELA = " << timePassedFormatted.ToString();
        m_prevStringSize = AsciiMisc().EraseLineGetPrevSize(oss.str(), m_prevStringSize);
    }
    m_prevPercentDone = percentDone;

    if (i == sz - 1)
    {
        //std::cout << "  Done!" << std::endl;
    }

}

void ProgressMonitHigh::Reset()
{
    *this = ProgressMonitHigh(m_numBars);
}
