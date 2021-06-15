#ifndef IVECT_HPP
#define IVECT_HPP

#include "../3rdParty/stdfwd.hh"
#include "Iters2.hpp"
#include "IIterable.hpp"
#include <cstddef>

namespace EnjoLib {
template <class T>
class IVecT : public IIterable<T>
{
    public:
        IVecT(){}
        virtual ~IVecT(){}
        
        virtual const T * data() const = 0;
        virtual T * data() = 0;
        
        virtual const stdfwd::vector<T> & Data() const = 0;
        virtual stdfwd::vector<T> DataCopy() const = 0;
        virtual stdfwd::vector<T> & DataRW() = 0;
        
        virtual const T & operator[](size_t idx) const = 0;
        virtual T & operator[](size_t idx) = 0;
        virtual void push_back(const T & val) = 0;
        virtual void emplace_back(const T & val) = 0;
        virtual size_t size() const = 0;
        virtual bool  empty() const = 0;
        virtual void  clear() = 0;
        
        virtual const T & First() const = 0;
        virtual const T & Last() const = 0;

        virtual T & First() = 0;
        virtual T & Last() = 0;
        
        virtual T & front() = 0;
        virtual T & back() = 0;
        
        virtual const T & front() const = 0;
        virtual const T & back() const = 0;

    protected:

    private:
};
}

#endif // IVECT_HPP
