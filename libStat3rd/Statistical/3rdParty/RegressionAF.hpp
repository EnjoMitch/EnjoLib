#ifndef REGRESSIONAF_H
#define REGRESSIONAF_H

#include <Statistical/RegressionAbstract.hpp>

namespace EnjoLib
{
class RegressionAF : public RegressionAbstract
{
    public:
        RegressionAF();
        virtual ~RegressionAF();
        
        EnjoLib::VecD polynomialfit(int degree, const EnjoLib::VecD & dx, const EnjoLib::VecD & dy) const override;

    protected:

    private:
};
}

#endif // REGRESSIONAF_H
