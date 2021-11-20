#ifndef REGRESSFACTORY_H
#define REGRESSFACTORY_H

#include <Statistical/RegressionFactoryAbstract.hpp>
#include <Template/CorradePointer.h>

namespace EnjoLib
{
class RegressionAbstract;
class RegressionFactory : public RegressionFactoryAbstract
{
    public:
        RegressionFactory();
        virtual ~RegressionFactory();

        virtual Corrade::Containers::Pointer<RegressionAbstract> CreateDefault() const override;
        virtual Corrade::Containers::Pointer<RegressionAbstract> Create(const RegressionAbstract::RegType & eigType) const override;

    protected:

    private:
};
}

#endif // EIGENFACTORY_H
