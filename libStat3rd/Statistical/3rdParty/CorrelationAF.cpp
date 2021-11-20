#include "CorrelationAF.hpp"

#include <stdexcept>

#ifdef WITH_FEATURE_ARRAY_FIRE
    #include <arrayfire.h>
#else
    #include <Statistical/Correlation.hpp>
#endif

CorrelationAF::CorrelationAF(const std::vector <float> & x, const std::vector <float> & y)
    :
    m_correlation(0) // suppress warning
{

    if ( x.size() != y.size() )
    {
        throw std::length_error("Correlation::Correlation(): Sizes should be equal.");
    }
    if ( x.empty() || y.empty() )
    {
        throw std::length_error("Correlation::Correlation(): Size should be greater than 0.");
    }

#ifdef WITH_FEATURE_ARRAY_FIRE
    af::array afx(x.size(), x.data());
    af::array afy(y.size(), y.data());

    m_correlation = af::corrcoef<float>(afx, afy);
#else
    m_correlation = 0; //Correlation()
#endif
}

double CorrelationAF::GetCorrelation() const
{
    return m_correlation;
}

