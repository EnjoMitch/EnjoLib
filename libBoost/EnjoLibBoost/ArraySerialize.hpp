#ifndef ARRAYSERIALIZE_HPP
#define ARRAYSERIALIZE_HPP

#include <Template/Array.hpp>

namespace EnjoLib {
template <class T>
template<class Archive>
void Array<T>::serialize(Archive & ar, const unsigned int version)
{
    ar & m_ptr.GetRW();
}

}
#endif // ARRAYSERIALIZE_HPP
