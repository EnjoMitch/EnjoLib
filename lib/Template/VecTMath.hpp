#ifndef VECTMATH_H
#define VECTMATH_H

#include <Template/IVecT.hpp>

namespace EnjoLib {
template <class T>
class VecTMath : public IVecT<T>
{
    public:
        VecTMath(){}
        virtual ~VecTMath(){}
        
        /// TODO:
        
        VecTMath<T> & operator += (const VecTMath<T> & par);
        VecTMath<T> & operator -= (const VecTMath<T> & par);
        VecTMath<T> & operator /= (const float f);
        VecTMath<T> & operator *= (const float f);
        VecTMath<T> & operator += (const float f);
        VecTMath<T> & operator -= (const float f);

        /*
        VecTMath<T> operator + (const VecTMath<T> & par) const;
        VecTMath<T> operator - (const VecTMath<T> & par) const;
        VecTMath<T> operator - () const;
        VecTMath<T> operator + (const float f) const;
        VecTMath<T> operator - (const float f) const;
        VecTMath<T> operator * (const float f) const;
        VecTMath<T> operator / (const float f) const;
        bool operator > (const VecTMath<T> & par) const;
        bool operator < (const VecTMath<T> & par) const;
        bool operator != (const VecTMath<T> & par) const;
        */
    protected:

    private:
};

}
#endif // VECTMATH_H
