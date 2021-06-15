#include "CorrelationAF.hpp"
#include <arrayfire.h>

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

    af::array afx(x.size(), x.data());
    af::array afy(y.size(), y.data());

    m_correlation = af::corrcoef<float>(afx, afy);
}

double CorrelationAF::GetCorrelation() const
{
    return m_correlation;
}

