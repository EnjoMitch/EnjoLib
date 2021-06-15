#include "ProgressMonitHigh.hpp"
#include "ProgressMonit.hpp"
#include "../Math/GeneralMath.hpp"
#include "../Util/TimeComponents.hpp"
#include <Util/Osstream.hpp>

#include <STD/Iostream.hpp>

using namespace std;
using namespace EnjoLib;

ProgressMonitHigh::ProgressMonitHigh(int numBars) : m_numBars(numBars) {}
ProgressMonitHigh::~ProgressMonitHigh(){}

void ProgressMonitHigh::PrintProgressBarTime(size_t i, size_t sz, const EnjoLib::Str & idd, bool onPercentChange) const
{
    Osstream oss;
    ProgressMonit pm(m_numBars);
    int percentDone = pm.GetPercentDoneInt(i, sz);
    if (! onPercentChange || percentDone != m_prevPercentDone)
    {
        for (int i = 0; i < m_prevStringSize; ++i)
            cout << '\b'; // Move back
        for (int i = 0; i < m_prevStringSize; ++i)
            cout << ' ';  // Erase by filling with spaces
        for (int i = 0; i < m_prevStringSize; ++i)
            cout << '\b'; // Move back again for the next printout

        double sec = m_timer.GetElapsedSeconds();
        double leftTime = GeneralMath().round(pm.GetTimeLeft(i, sz, sec));
        TimeComponents timeLeftFormatted(leftTime);
        TimeComponents timePassedFormatted(sec);

        oss << idd << ": i = " << i << " / " << sz << " = " << percentDone << "%" << " " << pm.GetProgressBar(i, sz)
        << " ETA = " << timeLeftFormatted.ToString() << ", ELA = " << timePassedFormatted.ToString();
        cout << oss.str() << flush;
        m_prevStringSize = oss.str().size();
    }
    m_prevPercentDone = percentDone;

    if (i == sz - 1)
        std::cout << "  Done!" << std::endl;
}

void ProgressMonitHigh::Reset()
{
    *this = ProgressMonitHigh(m_numBars);
}
