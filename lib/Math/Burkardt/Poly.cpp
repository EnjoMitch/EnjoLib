#include "Poly.hpp"
#include <STD/VectorCpp.hpp>

using namespace EnjoLib;

Poly::~Poly()
{
    //dtor
}

Poly::Poly(const double* c, std::size_t degree)
        : coeff(std::vector<double>(c, 1+c+degree)) {}

// ======================================================================
// Generally useful functor to evaluate a monic polynomial.
// For details, see class definition in brent.hpp
// Similarly, evaluate a general polynomial (not necessarily monic):
double Poly::operator()(double x)
{
    double rslt(0);
    for (int ii = coeff.size()-1; ii >= 0; ii--)
    {
        rslt *= x;
        rslt += coeff[ii];
    }
    return rslt;
}
