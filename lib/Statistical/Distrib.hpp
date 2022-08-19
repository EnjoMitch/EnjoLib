#ifndef DISTRIB_H
#define DISTRIB_H

#include <Util/StrFwd.hpp>
#include <Util/VecFwd.hpp>
#include <Util/Pair.hpp>
#include <Template/Array.hpp>

namespace EnjoLib
{

struct DistribData
{
    Array<Pair<FP, FP>> data;
    VecD GetY() const;
    VecD GetX() const;
    bool IsValid() const;
};

class Distrib
{
    public:
        Distrib();
        virtual ~Distrib();

        DistribData GetDistrib(const VecD & data, int numBins = 30) const;
        EnjoLib::Str PlotLine(const EnjoLib::DistribData & distrib, bool oneLiner = true, bool blocks = true, bool descr = true) const;
        
    protected:

    private:
};
}
#endif // DISTRIB_H
