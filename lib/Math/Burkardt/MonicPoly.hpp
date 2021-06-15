#ifndef MONICPOLY_H
#define MONICPOLY_H

#include "FuncBase.hpp"
#include <Util/VecD.hpp>

namespace EnjoLib {

class MonicPoly : public FuncBase
{
public:
    virtual ~MonicPoly();
    // constructors:
    MonicPoly(const std::size_t degree)
        : coeff(degree) {}
    MonicPoly(const VecD & v)
        : coeff(v) {}
    MonicPoly(const double* c, std::size_t degree);
        

    virtual double operator() (double x);

private:
    VecD coeff;
};
}

#endif // MONICPOLY_H
