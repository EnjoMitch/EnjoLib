#ifndef EIGENFACTORYABSTRACT_H
#define EIGENFACTORYABSTRACT_H

#include "EigenAbstract.hpp"
#include "../Template/CorradePointer.h"

namespace EnjoLib
{
class EigenAbstract;
class EigenFactoryAbstract
{
    public:
        EigenFactoryAbstract();
        virtual ~EigenFactoryAbstract();

        virtual Corrade::Containers::Pointer<EigenAbstract> Create(const EigenType & eigType) const = 0;

    protected:

    private:
};
}

#endif // EIGENFACTORYABSTRACT_H
