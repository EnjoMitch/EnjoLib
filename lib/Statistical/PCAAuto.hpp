#ifndef PCAAUTO_HPP
#define PCAAUTO_HPP

#include "Matrix.hpp"

namespace EnjoLib
{
class PCAAuto
{
    public:
        PCAAuto();
        virtual ~PCAAuto();

        int FindMinimalComponents(const Matrix & xxx, const double minQuality = 0.95) const;
        int FindMinimalComponentsBinSearch(const Matrix & xxx, const double minQuality = 0.95, const double minArg = 1) const;

        static double GetQuality(const Matrix & xxx, const Matrix & xxxT, const int feat2Leave);

    protected:

    private:
};
}

#endif // PCAAUTO_HPP
