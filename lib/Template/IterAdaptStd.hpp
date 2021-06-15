#ifndef ITERADAPTSTD_H
#define ITERADAPTSTD_H

#include <Template/IIterable.hpp>
#include <Util/Iters.hpp>

using namespace EnjoLib;

template <class T>
class IterAdaptStdConst
{
public:
    IterAdaptStdConst(const IIterableConst<T> * itr)
    : m_itr(itr)
    {
        
    }

    typedef blRawIterator<const T>        const_iterator;

    const_iterator       begin()  const { return const_iterator(m_itr->atUnsafe(0)); }
    const_iterator       end()    const { return const_iterator(m_itr->atUnsafe(m_itr->size())); }
    const_iterator       cbegin() const { return begin(); }
    const_iterator       cend()   const { return end(); }
    
private:
    const IIterableConst<T> * m_itr;
};


template <class T>
class IterAdaptStd : public IterAdaptStdConst<T>
{
public:
    IterAdaptStd(IIterable<T> * itr)
    : IterAdaptStdConst<T>(itr)
    , m_itr(itr)
    {
    }

    typedef blRawIterator<T>        iterator;
    
    iterator       begin()  { return iterator(m_itr->atwUnsafe(0)); }
    iterator       end()    { return iterator(m_itr->atwUnsafe(m_itr->size())); }

    
private:
    IIterable<T> * m_itr;
};


#endif // ITERADAPTSTD_H
