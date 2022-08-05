#include <Statistical/Distrib.hpp>

#include <Ios/Osstream.hpp>
#include <Ios/IoManip.hpp>
#include <Math/GeneralMath.hpp>
#include <Math/MaxMinFindD.hpp>
#include <Util/AlgoSTDIVec.hpp>
#include <Visual/AsciiPlot.hpp>
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

DistribData Distrib::GetDistrib(const EnjoLib::VecD & data, int numBins) const
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

VecD DistribData::GetY() const
{
    VecD dat;
    for (const Pair<double, double> & datPair : data)
    {
        dat.Add(datPair.second);
    }
    return dat;
}

VecD DistribData::GetX() const
{
    VecD dat;
    for (const Pair<double, double> & datPair : data)
    {
        dat.Add(datPair.first);
    }
    return dat;
}

Str Distrib::PlotLine(const EnjoLib::DistribData & distrib, bool oneLiner, bool blocks, bool descr) const
{
    Osstream oss;
    const int precision = 3;
    oss << IoManip::SetPrecision(oss, precision);
    const VecD & datx = distrib.GetX();
    const VecD & daty = distrib.GetY();
    const double maxY = daty.Max();
    MaxMinFindD mmf(daty);
    const auto idxMax = mmf.GetMaxIdx();
    const double medianX = datx.at(idxMax);

    Osstream ossPos;
    for (int i = 0; i < precision + 2 + idxMax; ++i)
    {
        ossPos << " ";
    }
    if (not oneLiner)
    {
        oss << Nl;
        oss << ossPos.str();
        if (maxY > 0) // Negative sign shifts the value left
        {
            //oss << "  ";
        }
        oss << maxY;
        oss << Nl;
    }
    if (descr)
    {
        oss << datx.Min();
    }
    oss << " " << AsciiPlot::Build()(AsciiPlot::Pars::BLOCKS, blocks)
    (AsciiPlot::Pars::MINIMUM, daty.Min())
    (AsciiPlot::Pars::MAXIMUM, daty.Max() * 0.99)
    .Finalize().Plot(daty) << " ";
    if (descr)
    {
        oss << datx.Max();
        oss << "  | Med = " << medianX << " (" << daty.Max() << ")" << ", Mean = " << datx.Mean();
    }
    if (not oneLiner)
    {
        oss << Nl;
        oss << ossPos.str() << medianX;
        oss << Nl;
    }
    return oss.str();
}
