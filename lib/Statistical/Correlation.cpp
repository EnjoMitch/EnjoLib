#include "Correlation.hpp"
#include <Util/Except.hpp>

#include <Util/Osstream.hpp>
#include <Util/CoutBuf.hpp>
#include <numeric>
#include <cmath>

using namespace EnjoLib;

double Correlation::GetCorrelation() const
{
    return m_correlation;
}


Correlation::Correlation ( const VecD & x, const VecD & y )
    :
    m_correlation(0) // suppress warning
{
    if ( x.size() != y.size() )
    {
        EnjoLib::Osstream oss;
        oss << "Correlation::Correlation(): Sizes should be equal. ";
        oss << "Got = " << x.size() << " and " << y.size();
        throw EnjoLib::ExceptLengthError(oss.str());
    }
    if ( x.empty() || y.empty() )
    {
        EnjoLib::Osstream oss;
        oss << "Correlation::Correlation(): Size should be greater than 0. ";
        oss << "Got = " << x.size() << " and " << y.size();
        throw EnjoLib::ExceptLengthError(oss.str());
    }
    if ( x.size() < 2 )
    {
        EnjoLib::Osstream oss;
        oss << "Correlation::Correlation(): Size should be greater than 2. ";
        oss << "Got = " << x.size() << " and " << y.size();
        throw EnjoLib::ExceptLengthError(oss.str());
    }
    m_correlation = Calculate(x, y);
}


double Correlation::Calculate(const VecD & x, const VecD & y) const
{
    const double meanX = Mean(x);
    const double meanY = Mean(y);

    const double sumNumerator = SumNumerator(x, y, meanX, meanY);

    const double sqrtSumSquareX = SqrtSumSquare( x, meanX );
    const double sqrtSumSquareY = SqrtSumSquare( y, meanY );
    const double denominator = sqrtSumSquareX * sqrtSumSquareY;

    if (denominator == 0)
    {
        ELO
        EnjoLib::Osstream oss;
        oss << "Correlation::Calculate(): Denominator is == 0, " << "meanX = " << meanX << ", meanY = " << meanY;
        LOG << oss.str() << NL3;
        return 0;
        throw EnjoLib::ExceptRuntimeError(oss.str());
    }
    return sumNumerator / denominator;
}


double Correlation::Mean(const VecD & ar) const
{
    double sum = std::accumulate(ar.begin(), ar.end(), 0.0);
    return sum / (double) ar.size();
}


double Correlation::SqrtSumSquare(const VecD & ar, double mean) const
{
    double sum = 0;
    for (size_t i = 0; i < ar.size(); ++i)
    {
        double var = (ar[i] - mean);
        sum += var * var;
    }
    return std::sqrt(sum);
}


double Correlation::SumNumerator(const VecD & x, const VecD & y, double meanX, double meanY) const
{
    double sumNumerator = 0;
    for (size_t i = 0; i < x.size() && i < y.size(); ++i)
    {
        sumNumerator += (x[i] - meanX) * (y[i] - meanY);
    }
    return sumNumerator;
}
