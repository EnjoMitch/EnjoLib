#ifndef VIEW_HPP
#define VIEW_HPP

#include <Template/IIterable.hpp>

namespace EnjoLib {

template <class T>
class View : public IIterableConst<T>
{
    public:
        View(const IIterableConst<T> & obj)
        : m_pobj(&obj)
        {
            
        }
        virtual ~View(){}
        
        const T & at(size_t idx) const override
        {
            return m_pobj->at(idx);
        }
        size_t size() const override
        {
            return m_pobj->size();
        }
        
        IITER_IMPL_TEMPLATE_CONST

    protected:

    private:
        const IIterableConst<T> * m_pobj;
};

template <class T> typename View<T>::const_iterator View<T>::begin() const    {return const_iterator(m_pobj->begin());}
template <class T> typename View<T>::const_iterator View<T>::end()   const    {return const_iterator(m_pobj->end());}
template <class T> typename View<T>::const_iterator View<T>::cbegin() const   {return begin();}
template <class T> typename View<T>::const_iterator View<T>::cend()   const   {return end();}

}
#endif // VIEW_HPP
