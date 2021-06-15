#ifndef PIMPLFAST_HPP_INCLUDED
#define PIMPLFAST_HPP_INCLUDED

#include "../Template/SafePtrFast.hpp"

//#ifdef PIMPL_THIN
//    #undef PIMPL_THIN
//#endif

#define PIMPL_GUTS \
private: \
    struct Impl; \
    struct PimplDeleter { void operator()(Impl*) const; }; \
    struct PimplCopier { Impl* operator()(const Impl*) const; }; \
    Impl & GetImplRW() { return *m_impl; } \
    const Impl & GetImpl() const { return *m_impl; }  

#define PIMPL_FAST \
    PIMPL_GUTS \
    EnjoLib::SafePtrFast<Impl, PimplDeleter> m_impl;
    
#define PIMPL_FAST_CPY \
    PIMPL_GUTS \
    EnjoLib::SafePtrCpy<Impl, PimplDeleter, PimplCopier, EnjoLib::SafePtrFast<Impl, PimplDeleter>> m_impl;

#endif // PIMPLFAST_HPP_INCLUDED
