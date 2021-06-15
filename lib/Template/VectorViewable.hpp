#ifndef VECTORVIEWABLE_HPP
#define VECTORVIEWABLE_HPP

#include <Template/IIterable.hpp>
#include <STD/Vector.hpp>

namespace EnjoLib {

template <class T>
class VectorViewable : public IIterable<T> 
{
    public:
        VectorViewable(const std::vector<T> & dat)
        : dat(dat)
        {
        }
        VectorViewable()
        {
        }
        virtual ~VectorViewable(){}
        
        const T & at(size_t idx) const override
        {
            return dat.at(idx);
        }
        T & atw(size_t idx) override
        {
            return dat.at(idx);
        }
        size_t size() const override
        {
            return dat.size();
        }
        
        IITER_IMPL_TEMPLATE_TYPES
        IITER_IMPL
        
        std::vector<T> dat;

    protected:

    private:
};

template <class T> typename VectorViewable<T>::iterator VectorViewable<T>::begin()          {return iterator(&dat.data()[0]);}
template <class T> typename VectorViewable<T>::iterator VectorViewable<T>::end()            {return iterator(&dat.data()[dat.size()]);}
template <class T> typename VectorViewable<T>::const_iterator VectorViewable<T>::begin() const    {return const_iterator(&dat.data()[0]);}
template <class T> typename VectorViewable<T>::const_iterator VectorViewable<T>::end()   const    {return const_iterator(&dat.data()[dat.size()]);}
template <class T> typename VectorViewable<T>::const_iterator VectorViewable<T>::cbegin() const   {return begin();}
template <class T> typename VectorViewable<T>::const_iterator VectorViewable<T>::cend()   const   {return end();}

}
#endif // VECTORVIEWABLE_HPP
