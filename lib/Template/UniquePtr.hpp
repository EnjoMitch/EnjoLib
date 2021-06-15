#ifndef UNIQUEPTR_H
#define UNIQUEPTR_H

#include "PtrHelper.hpp"
#include <memory>
#include <typeinfo>

namespace EnjoLib
{
template <class T, class D=std::default_delete<T> >
class UniquePtr : public std::unique_ptr<T, D>
{
    public:
        using Base = std::unique_ptr<T, D>;
        using Base::unique_ptr;
        using value_type = T;

        constexpr static const char * className = "UniquePtr";

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

#endif // UNIQUEPTR_H
