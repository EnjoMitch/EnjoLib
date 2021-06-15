#ifndef MAXMINFINDALL_H
#define MAXMINFINDALL_H

#include <Template/IVecT.hpp>
#include <Template/VecT.hpp>
#include "MaxMinFind.hpp"

namespace EnjoLib
{
template <class T>
class MaxMinFindAll
{
    public:
        MaxMinFindAll(const IVecT<T> & data, int surrounding = 1)
        : m_surrounding(surrounding)
        {
            CalcMinMax(data);
        }
        virtual ~MaxMinFindAll(){}

        typedef VecT<T>   ExtremaVal;
        typedef VecT<int> ExtremaIdx;

        const ExtremaVal & GetMinimaVal() const {return m_minimaVal;}
        const ExtremaVal & GetMaximaVal() const {return m_maximaVal;}
        const ExtremaIdx & GetMinimaIdx() const {return m_minimaIdx;}
        const ExtremaIdx & GetMaximaIdx() const {return m_maximaIdx;}

    protected:

    private:
        void CalcMinMax(const IVecT<T> & data);

        int m_surrounding = 1;
        ExtremaVal m_minimaVal, m_maximaVal;
        ExtremaIdx m_minimaIdx, m_maximaIdx;
};


template <class T>
void MaxMinFindAll<T>::CalcMinMax(const IVecT<T> & data)
{
    for (int i = m_surrounding; i < int(data.size()) - m_surrounding; ++i)
    {
        MaxMinFind<T> minMax;
        for (int j = i - m_surrounding; j < i + m_surrounding + 1; ++j)
        {
            const T & val = data.at(j);
            if (minMax.UpdateMax(val, j))
            {
                int a = 0;
                int b = a;
            }
            if (minMax.UpdateMin(val, j))
            {
                int a = 0;
                int b = a;
            }
        }
        const int maxIdx = minMax.GetMaxIdx();
        const int minIdx = minMax.GetMinIdx();
        //std::cout
        if (maxIdx == i)
        {
            m_maximaVal.push_back(minMax.GetMax());
            m_maximaIdx.push_back(maxIdx);
        }
        else
        if (minIdx == i)
        {
            m_minimaVal.push_back(minMax.GetMin());
            m_minimaIdx.push_back(minIdx);
        }
    }
}


}

#endif // MAXMINFINDALL_H
