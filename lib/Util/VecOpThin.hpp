#ifndef VECOPTHIN_HPP
#define VECOPTHIN_HPP

#include <Template/IVecT.hpp>

namespace EnjoLib
{
class VecD;
class VecOpThin
{
    public:
        VecOpThin(){}
        virtual ~VecOpThin(){}
        
        //template <class T> void AddRef(const EnjoLib::IVecT<T> & one, EnjoLib::IVecT<T> * two) const;
        void AddRef(const EnjoLib::VecD & one, EnjoLib::VecD * two) const;
        template <class T> int FindMaxIdx(const EnjoLib::IVecT<T> & v) const;
        template <class T> int FindMinIdx(const EnjoLib::IVecT<T> & v) const;


    protected:

    private:
};

/*
template <class T>
void VecOpThin::AddRef(const EnjoLib::IVecT<T> & a, EnjoLib::IVecT<T> * two) const
{
    std::copy (a.begin(), a.end(), std::back_inserter(*two));
}
*/

template <class T>
int VecOpThin::FindMaxIdx(const EnjoLib::IVecT<T> & v) const
{
    T mv = -1;
    int mi = -1;
    for (unsigned i = 0; i < v.size(); ++i)
    {
        const T & val = v.at(i);
        if (mi == -1 || val > mv)
        {
            mi = i;
            mv = val;
        }
    }
    return mi;
}

template <class T>
int VecOpThin::FindMinIdx(const EnjoLib::IVecT<T> & v) const
{
    T mv = -1;
    int mi = -1;
    for (unsigned i = 0; i < v.size(); ++i)
    {
        const T & val = v.at(i);
        if (mi == -1 || val < mv)
        {
            mi = i;
            mv = val;
        }
    }
    return mi;
}

}
#endif // VECOPTHIN_HPP
