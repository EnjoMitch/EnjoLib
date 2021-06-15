#ifndef ALGOSTDIVEC_HPP
#define ALGOSTDIVEC_HPP

//#include "../Util/IVec.hpp"
#include "../Template/IVecT.hpp"
#include "../Template/IIterable.hpp"
#include <cstddef>
/// TODO: Use IIterable, but IVecT<T> crashes in system test - invalid pointer.
namespace EnjoLib
{
    template <class T>
    class AlgoSTDIVec
    {
        public:
            void Sort(IVecT<T>    * v) const;            
            void Reverse(IVecT<T> * v) const;
            //size_t RemoveDuplicatesKeepOrder(IVecT<T> * vec) const;
            //void Shuffle(IVecT<T> * pvec) const;

            T SumLast(const IVecT<T> & v, std::size_t num) const;
            
            //T Last(const IVecT<T> & v) const;
    };
}

#endif // ALGOSTDIVEC_HPP
