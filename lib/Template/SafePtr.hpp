#ifndef SAFEPTR_HPP
#define SAFEPTR_HPP

#include "SafePtrThin.hpp"
#include <typeinfo>

namespace EnjoLib {

template<class T, class Deleter=DefaultPtrDeleter<T>, class Base=NonCopyable>
class SafePtr : public SafePtrThin<T, Deleter, Base>
{
public:
    using value_type = T;

    SafePtr()
    : SafePtrThin<T, Deleter, Base>()
    {

    }
    SafePtr(T * ptr)
    : SafePtrThin<T, Deleter, Base>(ptr)
    {

    }
    virtual const char * GetNameWrapper() const override
    {
        return className;
    }
    virtual void GetName(const T * ptr, char * buf, int szMax) const override
    {
        const char * typeName = typeid(ptr).name();
        PtrHelper::Copy(buf, typeName, szMax);
    }

private:
    constexpr static const char * className = "SafePtr";
};
}

#endif // SAFEPTR_HPP
