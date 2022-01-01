#ifndef ALGOSTDNUMERIC_HPP
#define ALGOSTDNUMERIC_HPP

#include <STD/Vector.hpp>
#include <cstddef>

namespace EnjoLib
{
    template <class T>
    class AlgoSTDNumeric
    {
        public:
            AlgoSTDNumeric();
            virtual ~AlgoSTDNumeric();

            T SumLast(const std::vector<T>    & v, std::size_t num) const;

        protected:

        private:
    };
}

#endif // ALGOSTDNUMERIC_HPP
