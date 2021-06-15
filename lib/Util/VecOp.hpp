#ifndef VECOP_H
#define VECOP_H

#include <Template/Array.hpp>
#include <STD/Vector.hpp>

namespace EnjoLib
{
class VecD;
class VecOp
{
    public:
        template <class T> Array<T> AddArr(const Array<T> & one, const Array<T> & two) const;
        template <class T> std::vector<T> Add(const std::vector<T> & one, const std::vector<T> & two) const;
        template <class T> std::vector<T> AddConstMem(const std::vector<T> & one, const std::vector<T> & two) const;
        template <class T> std::vector<std::vector<T> > Split(const std::vector<T> & one, std::size_t num) const;
        template <class T> void AddRef(const std::vector<T> & one, std::vector<T> * two) const;
        template <class T> int FindMaxIdx(const std::vector<T> & v) const;
        template <class T> int FindMinIdx(const std::vector<T> & v) const;

    protected:
    private:
};

template <class T>
std::vector<T> VecOp::Add(const std::vector<T> & a, const std::vector<T> & b) const
{
    std::vector<T> ret(a);
    ret.insert(ret.end(), b.begin(), b.end());
    return ret;
}

template <class T> 
Array<T> VecOp::AddArr(const Array<T> & one, const Array<T> & two) const
{
    std::vector<T> oneV;
    std::vector<T> twoV;
    AR2VEC(one, oneV)
    AR2VEC(two, twoV)
    const std::vector<T> ret = Add(oneV, twoV);
    return ret;
}

template <class T>
std::vector<T> VecOp::AddConstMem(const std::vector<T> & a, const std::vector<T> & b) const
{
    std::vector<T> ret(a);
    std::copy (b.begin(), b.end(), std::back_inserter(ret));
    return ret;
}

template <class T>
std::vector<std::vector<T> > VecOp::Split(const std::vector<T> & one, std::size_t num) const
{
    std::vector<std::vector<T> > ret;
    if (num == 0)
    {
        return ret;
    }
    if (num == 1)
    {
        ret.push_back(one);
        return ret;
    }
    const std::size_t len = one.size();
    const std::size_t numPerSlice = len / num;

    std::vector<T> accum;
    for (std::size_t i = 0; i < len; ++i)
    {
        const T & val = one.at(i);
        if (ret.size() == num)
        {
            ret.back().push_back(val);
        }
        else
        {
            accum.push_back(val);
            if (accum.size() >= numPerSlice)
            {
                ret.push_back(accum);
                accum.clear();
            }
        }
    }

    return ret;
}

template <class T>
void VecOp::AddRef(const std::vector<T> & a, std::vector<T> * two) const
{
    std::copy (a.begin(), a.end(), std::back_inserter(*two));
}

template <class T>
int VecOp::FindMaxIdx(const std::vector<T> & v) const
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
int VecOp::FindMinIdx(const std::vector<T> & v) const
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
#endif // VECOP_H
