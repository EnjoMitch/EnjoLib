#ifndef SAFEPTRBASECPY_HPP
#define SAFEPTRBASECPY_HPP

#include <Template/SafePtr.hpp>
#include <Util/BaseEmpty.hpp>


namespace EnjoLib {
    
template<class T>
struct DefaultPtrCopier
{
     T * operator()(const T* ptr) const
     {
         // intentionally complex - simplification causes regressions
         typedef char type_must_be_complete[ sizeof(T)? 1: -1 ];
         (void) sizeof(type_must_be_complete);
         return ptr;
     }
};
    
template<class T, class Deleter=DefaultPtrDeleter<T>, class Copier=DefaultPtrCopier<T>, class Ptr=SafePtr<T, Deleter, BaseEmpty>>
class SafePtrCpy : public Ptr
{
    public:
        using PtrType = Ptr;
        
        SafePtrCpy(T * ptr)
        : PtrType(ptr)
        {

        }
        virtual ~SafePtrCpy(){}
        
        SafePtrCpy(const SafePtrCpy & other)
        {
            Cpy(other);
        }
        SafePtrCpy & operator = (const SafePtrCpy & other)
        {
            Cpy(other);
            return *this;
        }
    protected:

    private:
        
        void Cpy(const SafePtrCpy & other)
        {
            const Copier copier;
            T * tnew = copier(other.get());
            this->Init(tnew);
        }
};

}
#endif // SAFEPTRBASECPY_HPP
