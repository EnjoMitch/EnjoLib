#include <Util/AlgoSTDIVec.hpp>

#include <Util/AlgoSTD.hpp>
#include <Util/VecD.hpp>
#include <Util/VecF.hpp>
#include <Util/Except.hpp>
#include <Util/Except.hpp>
#include <Template/IterAdaptStd.hpp>

#include <STD/Algorithm.hpp>
#include <STD/String.hpp>
#include <STD/VectorCpp.hpp>

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
void AlgoSTDIVec<T>::SumVectors(const IVecT<T> & vec1, const IVecT<T> & vec2, IVecT<T> * pvecOut) const
{
    pvecOut->clear();
    for (size_t i = 0; i < vec1.size(); ++i)
    {
        pvecOut->push_back(vec1.at(i));
    }
    for (size_t i = 0; i < vec2.size(); ++i)
    {
        pvecOut->push_back(vec2.at(i));
    }
}


namespace EnjoLib {
    template class AlgoSTDIVec<Str>;
    template class AlgoSTDIVec<string>;
    template class AlgoSTDIVec<float>;
    template class AlgoSTDIVec<double>;
    template class AlgoSTDIVec<int>;
    template class AlgoSTDIVec<unsigned long>;
    template class AlgoSTDIVec<unsigned long long>;
    template class AlgoSTDIVec<VecF>;
    template class AlgoSTDIVec<VecD>;
}
