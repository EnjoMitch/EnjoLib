#ifndef EIGENFACTORYABSTRACT_H
#define EIGENFACTORYABSTRACT_H

#include "../Template/CorradePointer.h"

namespace EnjoLib
{
class EigenAbstract;
class EigenFactoryAbstract
{
    public:
        EigenFactoryAbstract();
        virtual ~EigenFactoryAbstract();

        virtual Corrade::Containers::Pointer<EigenAbstract> CreateEigen() const = 0;

    protected:

    private:
};
}

#endif // EIGENFACTORYABSTRACT_H
