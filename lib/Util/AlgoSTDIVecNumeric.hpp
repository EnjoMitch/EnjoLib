#ifndef ALGOSTDIVECNUMERIC_HPP
#define ALGOSTDIVECNUMERIC_HPP

#include <Template/IVecT.hpp>
#include <Template/IIterable.hpp>
#include <cstddef>

namespace EnjoLib
{
    template <class T>
    class AlgoSTDIVecNumeric
    {
        public:
            AlgoSTDIVecNumeric();
            virtual ~AlgoSTDIVecNumeric();

            T SumLast(const IVecT<T>    & v, std::size_t num) const;

        protected:

        private:
    };
}


#endif // ALGOSTDIVECNUMERIC_HPP
