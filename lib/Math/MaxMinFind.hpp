#ifndef MAXMINFIND_H
#define MAXMINFIND_H

#include <cstdint>

namespace EnjoLib
{
    const static int64_t START_VAL = -1;
template <class T>
class MaxMinFind
{
    public:


        MaxMinFind()
        : min(START_VAL)
        , max(START_VAL)
        {

        }
        virtual ~MaxMinFind(){}
        bool UpdateMax(     const T & comp, int64_t i = START_VAL);
        bool UpdateMin(     const T & comp, int64_t i = START_VAL);
        void UpdateMaxMin(  const T & comp, int64_t i = START_VAL);
        void Reset();

        const T & GetMax()  const { return max; }
        const T & GetMin()  const { return min; }
        int64_t GetMaxIdx()     const { return imax;}
        int64_t GetMinIdx()     const { return imin;}

        bool IsMinValid() const { return min != START_VAL; }
        bool IsMaxValid() const { return max != START_VAL; }

    protected:

    private:

        T min;// = START_VAL;
        T max;// = START_VAL;
        int64_t imin = START_VAL;
        int64_t imax = START_VAL;
};

template <class T>
bool MaxMinFind<T>::UpdateMax(const T & comp, int64_t i)
{
    if (comp > max || max == START_VAL)
    {
        imax = i;
        max = comp;
        return true;
    }
    return false;
}

template <class T>
bool MaxMinFind<T>::UpdateMin(const T & comp, int64_t i)
{
    if (comp < min || min == START_VAL)
    {
        imin = i;
        min = comp;
        return true;
    }
    return false;
}

template <class T>
void MaxMinFind<T>::UpdateMaxMin(const T & comp, int64_t i)
{
    UpdateMax(comp, i);
    UpdateMin(comp, i);
}

template <class T>
void MaxMinFind<T>::Reset()
{
    *this = MaxMinFind<T>();
}
}

#endif // MAXMINFIND_H
