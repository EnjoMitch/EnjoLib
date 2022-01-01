#include "AlgoSTDIVecNumeric.hpp"

#include <Template/IterAdaptStd.hpp>
#include <Util/AlgoSTDNumeric.hpp>

#include <STD/VectorCpp.hpp>
#include <STD/String.hpp>

using namespace EnjoLib;

template <class T>
AlgoSTDIVecNumeric<T>::AlgoSTDIVecNumeric()
{
    //ctor
}

template <class T>
AlgoSTDIVecNumeric<T>::~AlgoSTDIVecNumeric()
{
    //dtor
}



template <class T>
T AlgoSTDIVecNumeric<T>::SumLast(const EnjoLib::IVecT<T> & ivec, std::size_t num) const
{
    /*
    if (num > v.size())
    {
        throw std::out_of_range("AlgoSTDIVecNumeric<T>::SumLast: size = " + to_string(v.size()) + ", requested = " + to_string(num) );
    }
    T sum {0};
    return std::accumulate(v.Data().cend() - num, v.Data().cend(), sum);

    //const IterAdaptStdConst<T> adapter(&v);
    //return std::accumulate(adapter.cend() - num, adapter.cend(), sum);
    */
    const IterAdaptStdConst<T> adapter(&ivec);

    const std::vector<T> & vec = ivec.Data();
    return AlgoSTDNumeric<T>().SumLast(vec, num);
}

namespace EnjoLib {
    template class AlgoSTDIVecNumeric<std::string>;
    template class AlgoSTDIVecNumeric<float>;
    template class AlgoSTDIVecNumeric<double>;
    template class AlgoSTDIVecNumeric<int>;
    template class AlgoSTDIVecNumeric<unsigned long>;
    template class AlgoSTDIVecNumeric<unsigned long long>;
}
