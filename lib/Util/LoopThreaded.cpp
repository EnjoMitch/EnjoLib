#include "LoopThreaded.hpp"
#include "../Statistical/Assertions.hpp"

using namespace EnjoLib;

LoopThreaded::~LoopThreaded(){}
LoopThreaded::LoopThreaded(int szz, int numCores)
: m_sz(szz)
, m_nCores(numCores)
{

}

int LoopThreaded::GetIdxOfDatasetForIteration(int i) const
{
    Assertions::IsTrue(i < m_sz, "Index greater than size of the loop");
    Assertions::IsTrue(i >= 0,   "Index negative");
    const float sizePerCore = m_sz / float(m_nCores);
    for (int div = 0; div < m_nCores; ++div)
    {
        if (div * sizePerCore <= i && i < (div + 1) * sizePerCore)
        {
            return div;
        }
    }
    return 0;
}

int LoopThreaded::GetSize() const
{
    return m_sz;
}

int LoopThreaded::GetNumCores() const
{
    return m_nCores;
}

//Example:
/*
static vector<Tick> GetTicksVec(int id, const VecStr & sss)
{
    vector<Tick> ticks;
    for (const string & s : sss)
        ticks.push_back(Tick(s));
    return ticks;
}

Ticks::Ticks(const string & symbolName, const VecStr & lines, bool skipHeader)
{
    m_ticks.clear();

    const Timer timer;
    const int numCores = thread::hardware_concurrency();
    const LoopThreaded loopThreaded(lines.size(), numCores);

    vector<VecStr> dataSets(numCores);
    for( int i = 0; i < int(lines.size()); ++i )
    {
        if (skipHeader)
        {
            skipHeader = false;
            continue;
        }
        const int dataSetIdx = loopThreaded.GetIdxOfDatasetForIteration(i);
        const string & s = lines[i];
        dataSets.at(dataSetIdx).push_back(s);
        //m_progressMonit.PrintProgressBarTime(m_ticks.size(), lines.size(), symbolName, true);
        //m_ticks.push_back(GetTick(0, s));
    }
    vector<future<vector<Tick>>> futures;
    for (const VecStr data : dataSets)
        futures.push_back(std::async (GetTicksVec, 0, data));
    for(auto &e : futures) {
        m_progressMonit.PrintProgressBarTime(m_ticks.size(), lines.size(), symbolName, true);
        for (const Tick & tick : e.get())
            m_ticks.push_back(tick);
    }
}
*/
