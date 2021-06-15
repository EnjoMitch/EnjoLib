#ifndef ALGOSTD_H
#define ALGOSTD_H

//#include "../Util/IVec.hpp"
#include <STD/Vector.hpp>
#include <deque>
#include <cstddef>

namespace EnjoLib
{
    template <class T>
    class AlgoSTD
    {
        public:           
            void Sort(std::vector<T> * v) const;
            void Sort(std::deque<T>  * v) const;
            
            void Reverse(std::vector<T> * v) const;
            void Reverse(std::deque<T>  * v) const;

            size_t RemoveDuplicatesKeepOrder(std::vector<T> * vec) const;
            void Shuffle(std::vector<T> * pvec) const;

            T SumLast(const std::vector<T>    & v, std::size_t num) const;
            
            T Last(const std::vector<T> & v) const;
    };
}

#endif // ALGOSTD_H
