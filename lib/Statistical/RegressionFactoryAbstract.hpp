#ifndef REGRESSIONFACTORYABSTRACT_H
#define REGRESSIONFACTORYABSTRACT_H

#include "RegressionAbstract.hpp"
#include "../Template/CorradePointer.h"

namespace EnjoLib
{
class RegressionFactoryAbstract
{
    public:
        RegressionFactoryAbstract();
        virtual ~RegressionFactoryAbstract();

        virtual Corrade::Containers::Pointer<RegressionAbstract> CreateDefault() const = 0;
        virtual Corrade::Containers::Pointer<RegressionAbstract> Create(const RegressionAbstract::RegType & eigType) const = 0;

    protected:

    private:
};
}

#endif // EIGENFACTORYABSTRACT_H
