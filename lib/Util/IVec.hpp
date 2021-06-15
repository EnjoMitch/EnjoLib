#ifndef IVEC_HPP
#define IVEC_HPP

//#include "../Util/Iters.hpp"
#include <cstddef>

namespace EnjoLib {
    
template<class T>
class IVec
{
    public:
        IVec(){}
        virtual ~IVec(){}
        
        using value_type = T;
        
        virtual const T & at(size_t idx) const = 0;
        virtual T & at(size_t idx) = 0;
        virtual const T & operator[](size_t idx) const = 0;
        virtual T & operator[](size_t idx) = 0;
        virtual void push_back(T val) = 0;
        virtual size_t size() const = 0;
        virtual bool empty() const = 0;

        /*
        typedef blRawIterator<T>              iterator;
        typedef blRawIterator<const T>        const_iterator;

        typedef blRawReverseIterator<T>       reverse_iterator;
        typedef blRawReverseIterator<const T> const_reverse_iterator;
        
        virtual const_iterator                                       begin() const = 0;
        virtual const_iterator                                       end() const = 0;
        
        virtual iterator                                       begin() = 0;
        virtual iterator                                       end() = 0;

        virtual const_iterator                                 cbegin() const = 0;
        virtual const_iterator                                 cend() const = 0;

        virtual reverse_iterator                               rbegin() = 0;
        virtual reverse_iterator                               rend() = 0;

        virtual const_reverse_iterator                         crbegin() const = 0;
        virtual const_reverse_iterator                         crend() const = 0;
        */
    protected:

    private:
};
}

#endif // IVEC_HPP
