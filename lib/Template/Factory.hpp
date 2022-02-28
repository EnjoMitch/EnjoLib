#ifndef FACTORY_H
#define FACTORY_H

#include <Util/Str.hpp>
#include <Template/CorradePointer.h>

namespace EnjoLib
{

template <class T>
class Factory
{
    public:
        Factory(){}
        virtual ~Factory(){}

        virtual CorPtr<T> Create(const EnjoLib::Str & params = "") const = 0;

    protected:

    private:
};
}
#endif // FACTORY_H
