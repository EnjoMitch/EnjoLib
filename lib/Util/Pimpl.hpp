#ifndef PIMPL_HPP_INCLUDED
#define PIMPL_HPP_INCLUDED

#include "PimplThin.hpp"
//#include "../Template/CorradePointer.h" // Heavier
#include "../Template/SafePtr.hpp"
#include "../Template/SafePtrCpy.hpp"
//#include <typeinfo>

//#ifdef PIMPL
//    #undef PIMPL
//#endif
//#ifdef PIMPL_CLASS
//    #undef PIMPL_CLASS
//#endif

//#define PIMPL_CLASS(Type) 
//    int a;
//    static const char * GetName() { return #Type; }


#define PIMPL \
    PIMPL_GUTS \
    EnjoLib::SafePtrFast<Impl, PimplDeleter> m_impl;
    
#define PIMPL_LAX \
    PIMPL_GUTS \
    EnjoLib::SafePtr<Impl, PimplDeleter> m_impl;
    
#define PIMPL_CPY \
    PIMPL_GUTS \
    EnjoLib::SafePtrCpy<Impl, PimplDeleter, PimplCopier, EnjoLib::SafePtr<Impl, PimplDeleter>> m_impl;


#endif // PIMPL_HPP_INCLUDED
