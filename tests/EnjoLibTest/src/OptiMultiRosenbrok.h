#ifndef OPTIMULTIROSENBROK_H
#define OPTIMULTIROSENBROK_H

#include <Math/Opti/OptiMultiSubject.hpp>
namespace EnjoLib
{
class OptiMultiRosenbrok : public OptiMultiSubject
{
    public:
        OptiMultiRosenbrok();
        virtual ~OptiMultiRosenbrok();

        double Get(const VecD & in);
        FP Get(const FP * in, int n) override;
        VecD GetStart() const override;
        VecD GetStep() const override;

        Array<OptiMultiSubject::Bounds> GetBounds() const override;

    protected:
    private:
};
}

#endif // OPTIMULTIROSENBROK_H
