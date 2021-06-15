#ifndef SPLINELIN_H
#define SPLINELIN_H

#include <Util/VecD.hpp>
#include <Template/SafePtr.hpp>
#include "../Systems/Point.hpp"

namespace EnjoLib
{
class SplineLin
{
    public:
        SplineLin(const EnjoLib::VecD & in);
        virtual ~SplineLin();

        double Interpol(double x) const;

        EnjoLib::VecD Scale(int outSize) const;

        EnjoLib::VecD ScaleUp(int outSize) const;
        EnjoLib::VecD ScaleDown(int outSize) const;

    protected:

    private:
        int GetSplineSize() const;
        SafePtr<stdfwd::vector<std::pair<EnjoLib::Point, EnjoLib::Point> > > spline;
};
}
#endif // SPLINELIN_H
