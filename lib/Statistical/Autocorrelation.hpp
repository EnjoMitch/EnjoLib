#ifndef AUTOCORRELATION_HPP
#define AUTOCORRELATION_HPP

#include "../Util/Pimpl.hpp"

namespace EnjoLib
{
class VecD;
class Autocorrelation
{
    PIMPL
    public:
        Autocorrelation(const VecD & data, unsigned periodMax);
        virtual ~Autocorrelation();

        VecD Calc(unsigned idx) const;
        double Calc2( unsigned idx, unsigned per) const;
        unsigned GetPeriodMax() const;

    protected:

    private:
        unsigned m_periodMax;
};
}

#endif // AUTOCORRELATION_HPP
