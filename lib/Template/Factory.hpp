#ifndef FACTORY_H
#define FACTORY_H

#include <Template/CorradePointer.h>

namespace EnjoLib
{
    
template <class T>
class Factory
{
    public:
        Factory(){}
        virtual ~Factory(){}
        
        virtual CorPtr<T> Create() const = 0;

    protected:

    private:
};
}
#endif // FACTORY_H
