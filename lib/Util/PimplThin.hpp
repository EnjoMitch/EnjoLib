#ifndef PIMPLTHIN_HPP_INCLUDED
#define PIMPLTHIN_HPP_INCLUDED

#include "PimplFast.hpp"
#include "../Template/SafePtrThin.hpp"

//#ifdef PIMPL_THIN
//    #undef PIMPL_THIN
//#endif

#define PIMPL_THIN \
    PIMPL_GUTS \
    EnjoLib::SafePtrThin<Impl, PimplDeleter> m_impl;
    
#define PIMPL_THIN_CPY \
    PIMPL_GUTS \
    EnjoLib::SafePtrCpy<Impl, PimplDeleter, PimplCopier, EnjoLib::SafePtrThin<Impl, PimplDeleter>> m_impl;

#endif // PIMPLTHIN_HPP_INCLUDED
