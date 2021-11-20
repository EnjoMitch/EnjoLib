#ifndef PCAAUTO_HPP
#define PCAAUTO_HPP

#include "Matrix.hpp"

namespace EnjoLib
{
class EigenAbstract;
class PCAAuto
{
    public:
        PCAAuto();
        virtual ~PCAAuto();

        int FindMinimalComponents(const EigenAbstract & eigen, const Matrix & xxx, const double minQuality = 0.95) const;
        int FindMinimalComponentsBinSearch(const EigenAbstract & eigen, const Matrix & xxx, const double minQuality = 0.95, const double minArg = 1) const;

        static double GetQuality(const EigenAbstract & eigen, const Matrix & xxx, const Matrix & xxxT, const int feat2Leave);

    protected:

    private:
};
}

#endif // PCAAUTO_HPP
