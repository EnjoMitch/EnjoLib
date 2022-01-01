#include <Util/AlgoSTDIVec.hpp>

#include <Util/AlgoSTD.hpp>
#include <Util/VecD.hpp>
#include <Util/VecF.hpp>
#include <Util/Except.hpp>
#include <Util/Except.hpp>
#include <Template/IterAdaptStd.hpp>

#include <STD/Algorithm.hpp>
#include <STD/String.hpp>
//#include <unordered_set>
//#include <numeric>
//#include <random>

using namespace std;
using namespace EnjoLib;


template <class T>
void AlgoSTDIVec<T>::Sort(EnjoLib::IVecT<T> * v) const
{
    std::sort(v->DataRW().begin(), v->DataRW().end());
    
    IterAdaptStd<T> adapter(v);
    //std::sort(adapter.begin(), adapter.end()); /// TODO: Crashes SR @ LongWick (system test)
}


template <class T>
void AlgoSTDIVec<T>::Reverse(EnjoLib::IVecT<T>  * v) const
{
    std::reverse(v->DataRW().begin(), v->DataRW().end());
    
    IterAdaptStd<T> adapter(v);
    //std::reverse(adapter.begin(), adapter.end());
}

template<class T>
size_t AlgoSTDIVec<T>::RemoveDuplicatesKeepOrder(EnjoLib::IVecT<T> * pvec) const
{
    std::vector<T> & vec = pvec->DataRW();
    return AlgoSTD<T>().RemoveDuplicatesKeepOrder(&vec);
}

template<class T>
void AlgoSTDIVec<T>::Shuffle(EnjoLib::IVecT<T> * pvec) const
{
    std::vector<T> & vec = pvec->DataRW();
    AlgoSTD<T>().Shuffle(&vec);
}

template<class T>
T AlgoSTDIVec<T>::Last(const EnjoLib::IVecT<T> & ivec) const
{
    const std::vector<T> & vec = ivec.Data();
    return AlgoSTD<T>().Last(vec);
}

template <class T>
T AlgoSTDIVec<T>::SumLast(const EnjoLib::IVecT<T> & ivec, std::size_t num) const
{
    /*
    if (num > v.size())
    {
        throw std::out_of_range("AlgoSTDIVec<T>::SumLast: size = " + to_string(v.size()) + ", requested = " + to_string(num) );
    }
    T sum {0};
    return std::accumulate(v.Data().cend() - num, v.Data().cend(), sum);
    
    //const IterAdaptStdConst<T> adapter(&v);
    //return std::accumulate(adapter.cend() - num, adapter.cend(), sum);
    */
    const IterAdaptStdConst<T> adapter(&ivec);
    
    const std::vector<T> & vec = ivec.Data();
    return AlgoSTD<T>().SumLast(vec, num);
}


namespace EnjoLib {
    template class AlgoSTDIVec<string>;
    template class AlgoSTDIVec<float>;
    template class AlgoSTDIVec<double>;
    template class AlgoSTDIVec<int>;
    template class AlgoSTDIVec<unsigned long>;
    template class AlgoSTDIVec<unsigned long long>;
}
