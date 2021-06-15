#ifndef PIMPLCOPIER_HPP_INCLUDED
#define PIMPLCOPIER_HPP_INCLUDED

#define PIMPL_COPIER(ParentClass) \
    ParentClass::Impl * ParentClass::PimplCopier::operator()(const ParentClass::Impl*oldptr) const \
    { \
            if (oldptr != nullptr) \
            { \
                ParentClass::Impl * tnew = new ParentClass::Impl(*oldptr); \
                return tnew; \
            } \
            return nullptr; \
    } \
    


#endif // PIMPLCOPIER_HPP_INCLUDED
