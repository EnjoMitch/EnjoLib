#ifndef POLY_H
#define POLY_H

#include "FuncBase.hpp"
#include <Util/VecD.hpp>

namespace EnjoLib {

class Poly : public FuncBase
{
public:

    virtual ~Poly();

    // constructors:
    Poly(const std::size_t degree)
        : coeff(1+degree) {}
    Poly(const VecD & v)
        : coeff(v) {}
    Poly(const double* c, std::size_t degree);

    virtual double operator() (double x);

protected:
private:
    VecD coeff;    // a vector of size nterms i.e. 1+degree
};
}

#endif // POLY_H
