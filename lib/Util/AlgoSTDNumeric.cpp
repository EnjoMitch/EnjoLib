#include "AlgoSTDNumeric.hpp"

#include <Util/Except.hpp>

#include <STD/String.hpp>

#include <numeric>

using namespace std;
using namespace EnjoLib;

template <class T>
AlgoSTDNumeric<T>::AlgoSTDNumeric()
{
    //ctor
}

template <class T>
AlgoSTDNumeric<T>::~AlgoSTDNumeric()
{
    //dtor
}


template <class T>
T AlgoSTDNumeric<T>::SumLast(const std::vector<T> & v, std::size_t num) const
{
    if (num > v.size())
    {
        throw ExceptLengthError("AlgoSTDNumeric<T>::SumLast: size = " + to_string(v.size()) + ", requested = " + to_string(num) );
    }
    T sum = 0;
    return std::accumulate(v.cend() - num, v.cend(), sum);
}

namespace EnjoLib {
    //template class AlgoSTDNumeric<Str>;
    template class AlgoSTDNumeric<string>;
    template class AlgoSTDNumeric<float>;
    template class AlgoSTDNumeric<double>;
    template class AlgoSTDNumeric<int>;
    template class AlgoSTDNumeric<unsigned long>;
    template class AlgoSTDNumeric<unsigned long long>;
    //template class AlgoSTDNumeric<VecF>; // Won't work
    //template class AlgoSTDNumeric<VecD>; // Won't work
}
