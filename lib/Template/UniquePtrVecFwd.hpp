#ifndef UNIQUEPTRVECFWD_HPP_INCLUDED
#define UNIQUEPTRVECFWD_HPP_INCLUDED

#include <3rdParty/stdfwd.hh>
#include <Template/CorradePointerFwd.h>
#include <Util/NonCopyable.hpp>
namespace EnjoLib
{
    template <class T, class D> class UniquePtr;
    template <class T, class D, class B> class SafePtr;
}

template<class T, class D=std::default_delete<T>>
using VecUPtr = stdfwd::vector<EnjoLib::UniquePtr<T, D>>;
template<class T, class D=std::default_delete<T>, class B=EnjoLib::NonCopyable>
using VecUPtrNew = stdfwd::vector<EnjoLib::SafePtr<T, D, B>>;

#endif // UNIQUEPTRVECFWD_HPP_INCLUDED
