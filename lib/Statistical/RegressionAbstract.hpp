#ifndef RegressionAbstract_H
#define RegressionAbstract_H

#include <Template/CorradePointerFwd.h>
#include <Util/VecFwd.hpp>

namespace EnjoLib {
class RegressionAbstract
{
    public:
        RegressionAbstract();
        virtual ~RegressionAbstract();
        
        virtual EnjoLib::VecD polynomialfit(int degree, const EnjoLib::VecD & dx, const EnjoLib::VecD & dy) const = 0;
        
        enum class RegType
        {
             REG_GSL
            ,REG_EIGEN
            ,REG_AFIRE
        };
        
        //static Corrade::Containers::Pointer<RegressionAbstract> Create(const RegType & type);
        //static Corrade::Containers::Pointer<RegressionAbstract> CreateDefault();

    protected:

    private:
};
}

#endif // IREGRESSION_H
