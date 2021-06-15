#ifndef SHAREDPTR_H
#define SHAREDPTR_H

#include "PtrHelper.hpp"
#include <memory>
#include <typeinfo>

namespace EnjoLib
{
template <class T>
class SharedPtr : public std::shared_ptr<T>
{
    public:
        using Base = std::shared_ptr<T>;
        using Base::shared_ptr;
        using value_type = T;

        constexpr static const char * className = "SharedPtr";

        const T & operator * () const
        {
            ThrowIfCondMet();
            return Base::operator*();
        }

        const T * operator -> () const
        {
            ThrowIfCondMet();
            return Base::operator->();
        }

        T & operator * ()
        {
            ThrowIfCondMet();
            return Base::operator*();
        }

        T * operator -> ()
        {
            ThrowIfCondMet();
            return Base::operator->();
        }

        void ThrowIfCondMet() const
        {
            return PtrHelper::ThrowIfCondMet(not Base::operator bool(), className, typeid(value_type).name());
        }

    protected:

    private:
};
}

#endif // SHAREDPTR_H
