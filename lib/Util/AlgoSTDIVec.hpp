#ifndef ALGOSTDIVEC_HPP
#define ALGOSTDIVEC_HPP

//#include "../Util/IVec.hpp"
#include "../Template/IVecT.hpp"
#include "../Template/IIterable.hpp"
/// TODO: Should use IIterable, but IVecT<T> crashes in system test - invalid pointer.
namespace EnjoLib
{
    template <class T>
    class AlgoSTDIVec
    {
        public:
            void Sort(IVecT<T>    * v) const;
            void Reverse(IVecT<T> * v) const;
            void Shuffle(IVecT<T> * pvec) const;
            void SumVectors(const IVecT<T> & vec1, const IVecT<T> & vec2, IVecT<T> * pvecOut) const;
            size_t RemoveDuplicatesKeepOrder(IVecT<T> * vec) const;

            T Last(const IVecT<T> & v) const;
    };
}

#endif // ALGOSTDIVEC_HPP
