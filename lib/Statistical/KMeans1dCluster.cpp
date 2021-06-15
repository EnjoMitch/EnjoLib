#include "KMeans1dCluster.hpp"
#include <Util/AlgoSTDIVec.hpp>
#include <vector>

using namespace EnjoLib;

KMeans1dCluster::~KMeans1dCluster(){}

VecF KMeans1dCluster::GetMembersLevels(bool sorted) const
{
    VecF ret;
    for (unsigned i = 0; i < idPoints.size(); ++i)
    {
        int id = idPoints.at(i);
        ret.push_back(obs.at(id));
    }

    if (sorted)
        AlgoSTDIVec<float>().Sort(&ret);
    return ret;
}

void KMeans1dCluster::Recalc()
{
    const int sz = idPoints.size();
    if (sz > 0)
    {
        float sum = 0;
        for (int i = 0; i < sz; ++i)
        {
            const int id = idPoints.at(i);
            const float level = obs.at(id);
            sum += level;
        }
        const float l = sum / float(sz);
        level = l;
    }
}

void KMeans1dCluster::Reset()
{
    idPointsPrev = idPoints;
    idPoints.clear();
}

void KMeans1dCluster::Assign(int pid)
{
    idPoints.push_back(pid);
}

bool KMeans1dCluster::IsReassigned() const
{
    if (idPoints.size() != idPointsPrev.size())
        return true;
    for (unsigned i = 0; i < idPoints.size(); ++i)
    {
        if (idPoints.at(i) != idPointsPrev.at(i))
            return true;
    }
    return false;
}

bool KMeans1dCluster::operator < (const KMeans1dCluster & other) const
{
    return GetLevel() < other.GetLevel();
}
