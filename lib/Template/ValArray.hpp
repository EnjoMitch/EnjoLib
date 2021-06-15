#ifndef VALARRAY_H
#define VALARRAY_H

#include <STD/Vector.hpp>
#include <valarray>

namespace EnjoLib
{
template <class T>
class ValArray
{
    public:
        ValArray(const std::vector<T> & in)
        : m_arr(in.data(), in.size())
        {

        }
        virtual ~ValArray(){}

        const std::valarray<T> & GetArr() const { return m_arr; }
              std::valarray<T> & GetArrRW()     { return m_arr; }


    protected:

    private:

        std::valarray<T> m_arr;

};
}

#endif // VALARRAY_H
