#ifndef REGRESSIONEIGEN_H
#define REGRESSIONEIGEN_H

#include <Statistical/RegressionAbstract.hpp>

namespace EnjoLib {
class RegressionEigen : public RegressionAbstract
{
    public:
        RegressionEigen();
        virtual ~RegressionEigen();
        
        EnjoLib::VecD polynomialfit(int degree, const EnjoLib::VecD & dx, const EnjoLib::VecD & dy) const override;

    protected:

    private:
};
}

#endif // REGRESSIONEIGEN_H
