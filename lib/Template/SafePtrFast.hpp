#ifndef SAFEPTRFAST_HPP
#define SAFEPTRFAST_HPP

#include <Template/SafePtrBase.hpp>

namespace EnjoLib {

template<class T, class Deleter=DefaultPtrDeleter<T>, class Base=NonCopyable>
class SafePtrFast : public SafePtrBase<T, Deleter, Base>
{
public:
    using value_type = T;
    
    SafePtrFast(T * ptr)
    {
        this->Init(ptr);
    }
    virtual ~SafePtrFast(){}
    
protected:

private:

};
}

#endif // SAFEPTRFAST_HPP
