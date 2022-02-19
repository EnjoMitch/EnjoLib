#include "Distrib.hpp"

#include <Math/GeneralMath.hpp>
#include <Util/AlgoSTDIVec.hpp>
#include <Statistical/Statistical.hpp>
#include <Statistical/Assertions.hpp>

#include <STD/VectorCpp.hpp>

using namespace EnjoLib;

Distrib::Distrib()
{
    //ctor
}

Distrib::~Distrib()
{
    //dtor
}

DistribData Distrib::GetDistrib(const EnjoLib::VecD & data, int numBins) const /// TODO: Upstream
{
    DistribData distrib;
    EnjoLib::VecD dataSorted = data;
    AlgoSTDIVec<double>().Sort(&dataSorted);
    std::vector<Pair<double, double>> distribData;
    if (dataSorted.size() < 2)
    {
        return distrib;
    }
    const double lo = dataSorted.First();
    const double hi = dataSorted.Last();
    const double rangeDiff = hi - lo;
    const double binLen = rangeDiff / double(numBins);
    //const int nbinLo = gm.round((lo-rangeLo) / binLen);
    //const int nbinHi = gm.round((hi-rangeLo) / binLen);

    for (int i = 1; i < numBins; ++i)
    {
        const double valMin = lo + binLen * (i - 1);
        const double valMax = lo + binLen * (i);
        const double valMid = (valMax + valMin) / 2.0;
        int numOcurrences = 0;
        for (const double val : dataSorted)
        {
            if (valMin <= val && val <= valMax)
            {
                ++numOcurrences;
            }
            else
            {
                if (numOcurrences > 0)
                    break; // ?
            }
        }
        distribData.push_back(MakePair(valMid, static_cast<double>(numOcurrences)));
    }
    distrib.data = distribData;
    return distrib;
}

bool DistribData::IsValid() const
{
    return data.size() >= 2;
}
