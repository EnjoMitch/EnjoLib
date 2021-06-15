#include "VecT.hpp"

#include <Statistical/Assertions.hpp>
#include <Util/Str.hpp>
#include <Util/PimplDeleter.hpp>

#include <STD/String.hpp>
#include <vector>
#include <STD/Algorithm.hpp>

using namespace EnjoLib;

template <class T>
struct VecT<T>::Impl
{
    Impl() {}
    Impl(const std::vector<T> & init) : dat(init) {}
    Impl(const_iterator beg, const_iterator endd)
    {
        for (const_iterator it = beg; it != endd; ++it)
            dat.push_back(*it);
    }
    Impl( int n ) : dat(n) {}
    Impl( int n, const T & val ) : dat(n, val) {}
    
    std::vector<T> dat;
};

template <class T> VecT<T>::~VecT(){}
template <class T> VecT<T>:: VecT(): m_impl(new Impl()){}
template <class T> VecT<T>:: VecT(int n): m_impl(new Impl(n)){}
template <class T> VecT<T>:: VecT(int n, const T & val): m_impl(new Impl(n, val)){}
template <class T> VecT<T>:: VecT(const_iterator beg, const_iterator endd): m_impl(new Impl(beg, endd)){}
template <class T> VecT<T>:: VecT( const std::vector<T> & init ): m_impl(new Impl(init)){}
template <class T> VecT<T>:: VecT( const std::initializer_list<T> & init ): m_impl(new Impl(init)){}

template <class T>
VecT<T>::VecT( const VecT<T> & other )
: m_impl(new Impl(other.GetImpl().dat))
{

}

template <class T>
VecT<T> & VecT<T>::operator=(const VecT<T> & other)
{
     GetImplRW() = other.GetImpl();
     return *this;
}

template <class T> 
const T * VecT<T>::data() const
{
    return GetImpl().dat.data();
}

template <class T> 
T * VecT<T>::data()
{
    return GetImplRW().dat.data();
}

template <class T> 
const std::vector<T> & VecT<T>::Data() const
{
    return m_impl->dat;
}

template <class T> 
std::vector<T> VecT<T>::DataCopy() const
{
    return m_impl->dat;
}

template <class T> 
std::vector<T> & VecT<T>::DataRW()
{
    return m_impl->dat;
}

template <class T> 
const T & VecT<T>::at(size_t idx) const
{
    return m_impl->dat.at(idx);
}

template <class T> 
const T & VecT<T>::operator[](size_t idx) const
{
    return m_impl->dat[idx];
}

template <class T> 
size_t VecT<T>::size() const
{
    return Data().size();
}

template <class T> 
T &  VecT<T>::atw(size_t idx)
{
    return m_impl->dat.at(idx);
}

template <class T> 
T &  VecT<T>::operator[](size_t idx)
{
    return m_impl->dat.operator[](idx);
}

template <class T> 
void  VecT<T>::push_back(const T & val)
{
    return m_impl->dat.push_back(val);
}

template <class T> 
void VecT<T>::emplace_back(const T & val)
{
    return m_impl->dat.emplace_back(val);
}


template <class T> 
bool  VecT<T>::empty() const
{
    return m_impl->dat.empty();
}

template <class T> 
void VecT<T>::clear()
{
    m_impl->dat.clear();
}

template <class T> 
const T & VecT<T>::First() const
{
    Assertions::NonEmpty(*this, "First");
    return GetImpl().dat.front();
}

template <class T> 
const T & VecT<T>::Last() const
{
    Assertions::NonEmpty(*this, "Last");
    return GetImpl().dat.back();
}

template <class T> 
T & VecT<T>::First()
{
    Assertions::NonEmpty(*this, "First");
    return GetImplRW().dat.front();
}

template <class T> 
T & VecT<T>::Last()
{
    Assertions::NonEmpty(*this, "Last");
    return GetImplRW().dat.back();
}

template <class T> 
bool VecT<T>::Contains(const T & searched) const
{
    return std::find(m_impl->dat.begin(), m_impl->dat.end(), searched) != m_impl->dat.end();
}

template <class T> T & VecT<T>::front() {    return First();}
template <class T> T & VecT<T>::back() {     return Last();}
template <class T> const T & VecT<T>::front() const {return First();}
template <class T> const T & VecT<T>::back()  const {return Last();}

template <class T> typename VecT<T>::iterator VecT<T>::begin()          {return iterator(&m_impl->dat[0]);}
template <class T> typename VecT<T>::iterator VecT<T>::end()            {return iterator(&m_impl->dat[size()]);}
template <class T> typename VecT<T>::const_iterator VecT<T>::begin() const    {return const_iterator(&m_impl->dat[0]);}
template <class T> typename VecT<T>::const_iterator VecT<T>::end()   const    {return const_iterator(&m_impl->dat[size()]);}
template <class T> typename VecT<T>::const_iterator VecT<T>::cbegin() const   {return begin();}
template <class T> typename VecT<T>::const_iterator VecT<T>::cend()   const   {return end();}

namespace EnjoLib {
    PIMPL_DELETER_TEMPLATE_INSTANT(VecT, std::string)    
    PIMPL_DELETER_TEMPLATE_INSTANT(VecT, EnjoLib::Str)
    //PIMPL_DELETER_TEMPLATE_INSTANT(VecT, bool)
    PIMPL_DELETER_TEMPLATE_INSTANT(VecT, float)
    PIMPL_DELETER_TEMPLATE_INSTANT(VecT, double)
    PIMPL_DELETER_TEMPLATE_INSTANT(VecT, int)
    PIMPL_DELETER_TEMPLATE_INSTANT(VecT, long)
    PIMPL_DELETER_TEMPLATE_INSTANT(VecT, unsigned long)
    PIMPL_DELETER_TEMPLATE_INSTANT(VecT, unsigned long long)
    
    PIMPL_DELETER_TEMPLATE_INSTANT(VecT, std::string*)
    PIMPL_DELETER_TEMPLATE_INSTANT(VecT, EnjoLib::Str*)
    PIMPL_DELETER_TEMPLATE_INSTANT(VecT, bool*)
    PIMPL_DELETER_TEMPLATE_INSTANT(VecT, float*)
    PIMPL_DELETER_TEMPLATE_INSTANT(VecT, double*)
    PIMPL_DELETER_TEMPLATE_INSTANT(VecT, int*)
    PIMPL_DELETER_TEMPLATE_INSTANT(VecT, long*)
    PIMPL_DELETER_TEMPLATE_INSTANT(VecT, unsigned long*)
    PIMPL_DELETER_TEMPLATE_INSTANT(VecT, unsigned long long*)
    //PIMPL_DELETER(VecT<std::string>)
}
