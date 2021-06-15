#ifndef SAFEPTRTHIN_HPP
#define SAFEPTRTHIN_HPP

#include <Template/SafePtrBase.hpp>
#include "PtrHelper.hpp"

namespace EnjoLib {

template<class T, class Deleter=DefaultPtrDeleter<T>, class Base=NonCopyable>
class SafePtrThin : public SafePtrBase<T, Deleter, Base>
{
public:
    using value_type = T;
    
    SafePtrThin()
    {
    }
    SafePtrThin(T * ptr)
    {
        this->Init(ptr);
    }
    virtual ~SafePtrThin(){}

    virtual const char * GetNameWrapper() const
    {
        return className;
    }
    virtual void GetName(const T * ptr, char * buf, int szMax) const
    {
        PtrHelper::Copy(buf, "Undefined", szMax);
    }
    void CheckMe() const override
    {
        InitName();
        return PtrHelper::ThrowIfCondMet(not this->GetProt(), GetNameWrapper(), buf);
    }
protected:
    void InitName() const
    {
        if (isNameInit)
        {
            return;
        }
        isNameInit = true;
        GetName(this->GetProt(), buf, szMax);
    }
private:
    constexpr static const char * className = "SafePtrThin";
    static constexpr const int szMax = 100;
    mutable char buf[szMax];
    mutable bool isNameInit = false;
};
}

#endif // SAFEPTRTHIN_HPP
