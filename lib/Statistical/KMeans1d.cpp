#include <STD/Algorithm.hpp>
#include <Util/CoutBuf.hpp>

#include "KMeans1d.hpp"
#include "KMeans1dCluster.hpp"
#include "../Util/StackTrace.hpp"
#include "../Math/GeneralMath.hpp"
#include <Util/Except.hpp>
#include <Util/Osstream.hpp>

#include <STD/VectorCpp.hpp>

using namespace std;
using namespace EnjoLib;
KMeans1d::KMeans1d(bool clustersSorted)
: m_clustersSorted(clustersSorted)
{}
KMeans1d::~KMeans1d(){}


VecF KMeans1d::Reduce(int reductions) const
{
    const EnjoLib::Array<KMeans1dCluster> & clusters = ReduceGetClusters(reductions);
    VecF ret;
    for (unsigned ic = 0; ic < clusters.size(); ++ic)
        ret.push_back(clusters.at(ic).GetLevel());

    return ret;
}

EnjoLib::Array<KMeans1dCluster> KMeans1d::ReduceGetClusters(int reductions) const
{
    GeneralMath gm;
    if (reductions <= 0)
        return EnjoLib::Array<KMeans1dCluster>();

    const unsigned opSz = m_obs.size();
    const int nClusters = opSz - reductions;
    if (nClusters <= 0)
    {
        Osstream oss;
        oss << "Too large number of reductions = " << reductions << ", vs size of = " << opSz << NL2;
        throw ExceptRuntimeError(STRACE_THROW(oss.str()));
    }
    //return op;

    float lvlMax = m_obs.at(0);
    float lvlMin = m_obs.at(0);
    for (unsigned i = 0; i < opSz; ++i)
    {
        const float o = m_obs.at(i);
        if (o > lvlMax)
            lvlMax = o;
        if (o < lvlMin)
            lvlMin = o;
    }

    const VecD & distr = gm.UniformDistr(nClusters, lvlMin, lvlMax);
    vector<KMeans1dCluster> clusters;
    for (float lvl : distr)
    {
        KMeans1dCluster c(m_obs, lvl);
        clusters.push_back(c);
    }

    for(int iter = 0; iter < 200; ++iter)
    {
        const unsigned clSz = clusters.size();
        for (unsigned ic = 0; ic < clSz; ++ic)
            clusters.at(ic).Reset();

        for (unsigned io = 0; io < opSz; ++io)
        {
            // Assignment step:
            // Assign each observation to the cluster whose mean yields the least within-cluster sum of squares (WCSS).
            const float o = m_obs.at(io);
            const float minDistArtificial = -1001;
            float minDist = minDistArtificial;
            int minIc = 0;
            for (unsigned ic = 0; ic < clSz; ++ic)
            {
                const KMeans1dCluster & c = clusters.at(ic);
                const float dist = Dist(o, c.GetLevel());
                if (minDist == minDistArtificial || dist < minDist)
                {
                    minDist = dist;
                    minIc = ic;
                }
            }
            clusters.at(minIc).Assign(io);
        }
        for (unsigned ic = 0; ic < clSz; ++ic)
        {
            // Update step
            // Calculate the new means to be the centroids of the observations in the new clusters.
            clusters.at(ic).Recalc();
        }
        // Stop condition
        // Break if nothing was reassigned
        bool reassigned = false;
        for (unsigned ic = 0; ic < clSz; ++ic)
        {
            if (clusters.at(ic).IsReassigned())
            {
                reassigned = true; // At least one cluster was reassigned. Continue loop, as there's something to improve.
                break;
            }
        }
        if (!reassigned)
            break;
    }
    if (m_clustersSorted)
        std::sort(clusters.begin(), clusters.end());
    return clusters;
}

void KMeans1d::AddObservation(float obs)
{
    m_obs.push_back(obs);
}

float KMeans1d::Dist(float p, float c)
{
    const float d = p-c;
    const float d2 = d*d;
    return d2;
}

