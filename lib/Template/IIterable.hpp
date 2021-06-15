#ifndef IITERABLEAA_H
#define IITERABLEAA_H

#include "Iters2.hpp"
#include <cstddef>

namespace EnjoLib {
    
template <class T>
class IIterableConst
{
    public:
        IIterableConst(){}
        virtual ~IIterableConst(){}
        
        typedef Iter<T>              iterator;
        typedef Iter<const T>        const_iterator;

        virtual const_iterator       begin() const = 0;
        virtual const_iterator       end() const = 0;
        virtual const_iterator       cbegin() const = 0;
        virtual const_iterator       cend() const = 0;
        
        bool empty() const
        {
            return cbegin() == cend();
        }
        virtual const T & at(size_t idx) const = 0;
        const T & operator [](size_t idx) const 
        { 
            return *(cbegin() + idx); 
        };
        virtual size_t size() const = 0;
        
        const T * atUnsafe(size_t idx) const
        {
            return (cbegin() + idx).operator->(); 
        }
        

    protected:

    private:
};

template <class T>
class IIterable : public IIterableConst<T>
{
    public:
        IIterable(){}
        virtual ~IIterable(){}
        
        typedef Iter<T>              iterator;
        typedef Iter<const T>        const_iterator;

        virtual const_iterator       begin() const = 0;
        virtual const_iterator       end() const = 0;
        virtual iterator             begin() = 0;
        virtual iterator             end() = 0;
        
        virtual T & atw(size_t idx) = 0;
        
        T * atwUnsafe(size_t idx)
        {
            return (begin() + idx).operator->(); 
        }

    protected:

    private:
};
}

#define IITER_IMPL_CONST \
        virtual const_iterator       begin() const override; \
        virtual const_iterator       end() const override; \
        virtual const_iterator       cbegin() const override; \
        virtual const_iterator       cend() const override; \

#define IITER_IMPL \
        virtual const_iterator       begin() const override; \
        virtual const_iterator       end() const override; \
        virtual const_iterator       cbegin() const override; \
        virtual const_iterator       cend() const override; \
        virtual iterator             begin() override; \
        virtual iterator             end() override; \
        
#define IITER_IMPL_TEMPLATE_TYPES \
        typedef Iter<T>              iterator; \
        typedef Iter<const T>        const_iterator;
        
#define IITER_IMPL_TEMPLATE \
        IITER_IMPL_TEMPLATE_TYPES \
        IITER_IMPL
        
#define IITER_IMPL_TEMPLATE_CONST \
        IITER_IMPL_TEMPLATE_TYPES \
        IITER_IMPL_CONST

#endif // IITERABLE_H
