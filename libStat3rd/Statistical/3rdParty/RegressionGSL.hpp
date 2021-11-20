#ifndef REGRESSIONGSL_HPP
#define REGRESSIONGSL_HPP

#include <Statistical/RegressionAbstract.hpp>

namespace EnjoLib {
class RegressionGSL : public RegressionAbstract
{
    public:
        RegressionGSL();
        virtual ~RegressionGSL();
        
        EnjoLib::VecD polynomialfit(int degree, const EnjoLib::VecD & dx, const EnjoLib::VecD & dy) const override;

    protected:

    private:
};
}

#endif // REGRESSIONGSL_HPP
