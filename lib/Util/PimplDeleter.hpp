#ifndef PIMPLDELETER_HPP_INCLUDED
#define PIMPLDELETER_HPP_INCLUDED

//#include <Util/PimplDeleter.hpp>

#define PIMPL_DELETER(ParentClass) \
    void ParentClass::PimplDeleter::operator()(ParentClass::Impl*ptr) const { delete ptr; }
    
#define PIMPL_DELETER_TEMPLATE_INSTANT(ParentClass, Type) \
    template class ParentClass<Type>; \
    template <> void ParentClass<Type>::PimplDeleter::operator()(ParentClass<Type>::Impl*ptr) const { delete ptr; }

#endif // PIMPLDELETER_HPP_INCLUDED
