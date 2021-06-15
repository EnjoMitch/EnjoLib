#ifndef CORRELATION_HPP_INCLUDED
#define CORRELATION_HPP_INCLUDED

//#include <vector>
//#include <Util/Except.hpp>
//#include <numeric>
#include <Util/VecD.hpp>

namespace EnjoLib {
/**
http://en.wikipedia.org/wiki/Pearson_product-moment_correlation_coefficient
*/
class Correlation
{
public:
    Correlation( const VecD & x, const VecD & y);
    double GetCorrelation() const;

private:
    double Calculate(const VecD & x, const VecD & y) const;
    double Mean(const VecD & ar) const;
    double SqrtSumSquare(const VecD & ar, double mean) const;
    double SumNumerator(const VecD & x, const VecD & y, double meanX, double meanY) const;

    double m_correlation;
};
}

#endif // CORRELATION_HPP_INCLUDED
