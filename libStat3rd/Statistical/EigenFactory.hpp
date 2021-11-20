#ifndef EIGENFACTORY_H
#define EIGENFACTORY_H

#include <Statistical/EigenFactoryAbstract.hpp>
#include <Template/CorradePointer.h>

namespace EnjoLib
{
class EigenAbstract;
class EigenFactory : public EigenFactoryAbstract
{
    public:
        EigenFactory();
        virtual ~EigenFactory();

        virtual Corrade::Containers::Pointer<EigenAbstract> Create(const EigenType & eigType) const override;

    protected:

    private:
};
}

#endif // EIGENFACTORY_H
