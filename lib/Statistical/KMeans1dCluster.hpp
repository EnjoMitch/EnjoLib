#ifndef KMEANS1DCLUSTER_H
#define KMEANS1DCLUSTER_H

#include <Template/VecT.hpp>
#include <Util/VecF.hpp>

namespace EnjoLib
{
class KMeans1dCluster
{
    public:
        KMeans1dCluster(){}
        KMeans1dCluster(const VecF & obs, float val) : level(val), obs(obs) {}
        virtual ~KMeans1dCluster();
        void Reset();
        void Assign(int pid);
        void Recalc();
        bool IsReassigned() const;
        float GetLevel() const { return level; }
        VecF GetMembersLevels(bool sorted = false) const;

        bool operator < (const KMeans1dCluster & other) const;
    private:

        float level;
        EnjoLib::VecT<int> idPoints;
        EnjoLib::VecT<int> idPointsPrev;
        EnjoLib::VecF obs;
};
}

#endif // KMEANS1DCLUSTER_H
