#ifndef OPTIMULTIROSENBROK_H
#define OPTIMULTIROSENBROK_H

#include <Math/Opti/OptiMultiSubject.hpp>

class OptiMultiRosenbrok : public EnjoLib::OptiMultiSubject
{
    public:
        OptiMultiRosenbrok();
        virtual ~OptiMultiRosenbrok();

        double Get(const EnjoLib::VecD & in);
        double Get(const double * in, int n) override;
        EnjoLib::VecD GetStart() const override;
        EnjoLib::VecD GetStep() const override;

        stdfwd::vector<EnjoLib::OptiMultiSubject::Bounds> GetBounds() const override;

    protected:
    private:
};

#endif // OPTIMULTIROSENBROK_H
