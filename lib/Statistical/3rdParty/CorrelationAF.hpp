#ifndef CORRELATIONAF_H
#define CORRELATIONAF_H

namespace af
{
    class array;
}

#include <vector>

/**
http://en.wikipedia.org/wiki/Pearson_product-moment_correlation_coefficient
*/
class CorrelationAF
{
    public:
        CorrelationAF(const std::vector <float> & x, const std::vector <float> & y);
        virtual ~CorrelationAF(){}

        double GetCorrelation() const;

    protected:

    private:
        af::array Calculate(const af::array & x, const af::array & y) const;
        af::array Mean(const af::array & ar) const;
        af::array SqrtSumSquare(const af::array & ar, const af::array & mean) const;
        af::array SumNumerator(const af::array & x, const af::array & y, const af::array & meanX, const af::array & meanY) const;

        double m_correlation;
};

#endif // CORRELATIONAF_H
