#ifndef PAIR_EL_HPP
#define PAIR_EL_HPP

namespace EnjoLib
{
template <class T1, class T2>
class Pair
{
    public:
        Pair()
        {
            
        }
        Pair(const T1 & var1, const T2 & var2)
        : first(var1)
        , second(var2)
        {
            
        }
        virtual ~Pair(){}
        
        T1 first;
        T2 second;

    protected:

    private:
};

template <class T1, class T2>
Pair<T1, T2> MakePair(const T1 & var1, const T2 & var2)
{
    return Pair<T1, T2>(var1, var2);
}

template <class T1, class T2>
bool operator < (const Pair<T1, T2> & left, const Pair<T1, T2> & right)
{
    if (left.first == right.first)
    {
        return left.second < right.second;
    }
    return left.first < right.first;
}

}
#endif // PAIR_EL_HPP
