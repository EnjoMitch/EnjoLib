#ifndef KMeans1d_H
#define KMeans1d_H

#include <Util/VecF.hpp>
#include <Template/Array.hpp>

namespace EnjoLib
{
class KMeans1dCluster;

class KMeans1d
{
    public:
        KMeans1d(bool clustersSorted = false);
        virtual ~KMeans1d();

        void AddObservation(float obs);
        VecF Reduce(int reductions) const;
        EnjoLib::Array<KMeans1dCluster> ReduceGetClusters(int reductions) const;

        static float Dist(float p, float c);

    protected:

    private:
        bool m_clustersSorted = false;
        VecF m_obs;
};

}
#endif // KMeans1d_H
