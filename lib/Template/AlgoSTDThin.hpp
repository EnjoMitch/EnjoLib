#ifndef ALGOSTDTHIN_HPP
#define ALGOSTDTHIN_HPP

namespace EnjoLib {
class AlgoSTDThin
{
    public:
        AlgoSTDThin();
        virtual ~AlgoSTDThin();
        template <class T> const T & Min(const T & left, const T & right) const;
        template <class T> const T & Max(const T & left, const T & right) const;
        template <class T> void Swap(T & left, T & right) const;
        

    protected:

    private:
};

#define EL_MAX(x, y) x > y ? x : y

#define EL_MIN(x, y) x < y ? x : y


template <class T> const T & AlgoSTDThin::Min(const T & left, const T & right) const
{
    if (left < right)
    {
        return left;
    }
    else
    {
        return right;
    }
}

template <class T> const T & AlgoSTDThin::Max(const T & left, const T & right) const
{
    if (right < left)
    {
        return left;
    }
    else
    {
        return right;
    }
}

template <class T> void AlgoSTDThin::Swap(T & left, T & right) const
{
    T & tmp = left;
    left = right;
    right = tmp;
}

}

#endif // ALGOSTDTHIN_HPP
