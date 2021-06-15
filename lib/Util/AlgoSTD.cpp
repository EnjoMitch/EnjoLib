#include "AlgoSTD.hpp"
#include <Util/VecD.hpp>
#include <Util/VecF.hpp>
#include <Util/Str.hpp>
#include <STD/Algorithm.hpp>
#include <numeric>
#include <STD/String.hpp>
#include <unordered_set>
#include <random>
#include <Util/Except.hpp>

using namespace std;
using namespace EnjoLib;

template <class T>
void AlgoSTD<T>::Sort(std::vector<T> * v) const
{
    std::sort(v->begin(), v->end());
}

template <class T>
void AlgoSTD<T>::Sort(std::deque<T> * v) const
{
    std::sort(v->begin(), v->end());
}
template <class T>
void AlgoSTD<T>::Reverse(std::vector<T> * v) const
{
    std::reverse(v->begin(), v->end());
}

template <class T>
void AlgoSTD<T>::Reverse(std::deque<T> * v) const
{
    std::reverse(v->begin(), v->end());
}

template <class T>
T AlgoSTD<T>::SumLast(const std::vector<T> & v, std::size_t num) const
{
    if (num > v.size())
    {
        throw std::out_of_range("AlgoSTD<T>::SumLast: size = " + to_string(v.size()) + ", requested = " + to_string(num) );
    }
    T sum = 0;
    return std::accumulate(v.cend() - num, v.cend(), sum);
}

template<class T>
size_t AlgoSTD<T>::RemoveDuplicatesKeepOrder(std::vector<T> * pvec) const
{
    std::vector<T> & vec = *pvec;
    std::unordered_set<T> seen;

    const auto newEnd = std::remove_if(vec.begin(), vec.end(), [&seen](const T& value)
    {
        if (seen.find(value) != std::end(seen))
            return true;

        seen.insert(value);
        return false;
    });

    vec.erase(newEnd, vec.end());

    return vec.size();
}

template<class T>
void AlgoSTD<T>::Shuffle(std::vector<T> * pvec) const
{
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(*pvec), std::end(*pvec), rng);
}

template<class T>
T AlgoSTD<T>::Last(const std::vector<T> & v) const
{
    const auto ret = v.at(v.size() - 1);
    return ret; 
}


namespace EnjoLib {
    template class AlgoSTD<string>;
    template class AlgoSTD<float>;
    template class AlgoSTD<double>;
    template class AlgoSTD<int>;
    template class AlgoSTD<unsigned long>;
    template class AlgoSTD<unsigned long long>;
    //template class AlgoSTD<VecF>; // Won't work
    //template class AlgoSTD<VecD>; // Won't work
}
