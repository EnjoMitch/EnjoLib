#include "Autocorrelation.hpp"
#include "Correlation.hpp"
#include <Util/PimplDeleter.hpp>
#include "../Util/VecD.hpp"
#include <STD/Map.hpp>
#include <Util/CoutBuf.hpp>

using namespace std;
using namespace EnjoLib;

struct Autocorrelation::Impl
{
    Impl(const VecD & data)
    : m_data(data)
    {

    }
    VecD m_data;
    using Cache = std::map<int, VecD>;
    mutable Cache m_cache;
};
PIMPL_DELETER(Autocorrelation)

Autocorrelation::~Autocorrelation(){}
Autocorrelation:: Autocorrelation(const VecD & data, unsigned periodMax)
: m_impl(new Impl(data))
, m_periodMax(periodMax)
{}

VecD Autocorrelation::Calc( unsigned idx) const
{
    Impl::Cache::iterator it = m_impl->m_cache.find(idx);
    if (it != m_impl->m_cache.end())
    {
        return it->second;
    }
    const VecD & tss = m_impl->m_data;
    VecD ret;
    //return tss;
    const VecD & sample = tss.Slice(idx, m_periodMax);

    for (size_t i = idx - m_periodMax; i < idx; ++i)
    {
        //cout << "i = " << i << endl;
        const VecD & slice = tss.Slice(i, m_periodMax);
        //if (slice.at(0) == slice.Mean() )
        {
            //cout << "Same vector at " << idx << ": " << slice.Print() <<  "\n";
        }
        const Correlation corr(sample, slice);
        const double corVal = corr.GetCorrelation();

        ret.Add(corVal);
    }
    m_impl->m_cache.emplace(idx, ret);
    //cout << "corVal = " << ret.Print() << endl;
    return ret;
}

double Autocorrelation::Calc2( unsigned idx, unsigned per) const
{
    const VecD & tss = m_impl->m_data;
    VecD ret;
    //return tss;


    unsigned k = 0;
    for (size_t i = idx - m_periodMax; i < idx; ++i)
    {
        if (k++ < per)
        {
            continue;
        }
        const VecD & sample = tss.Slice(idx, m_periodMax);
        //cout << "i = " << i << endl;
        const VecD & slice = tss.Slice(i, m_periodMax);
        //if (slice.at(0) == slice.Mean() )
        {
            //cout << "Same vector at " << idx << ": " << slice.Print() <<  "\n";
        }
        const Correlation corr(sample, slice);
        const double corVal = corr.GetCorrelation();

        return corVal;
    }
    //cout << "corVal = " << ret.Print() << endl;
    return 0;
}

unsigned Autocorrelation::GetPeriodMax() const
{
    return m_periodMax;
}
