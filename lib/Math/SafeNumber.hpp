#ifndef SAFENUMBER_H
#define SAFENUMBER_H

#include <Util/Except.hpp>
#include <STD/Ostream.hpp>

namespace EnjoLib
{

class IHasNumber
{
public:
    virtual double GetNumber() const = 0;
};

template<class T>
class SafeNumber : public IHasNumber
{
    public:
        SafeNumber(T val = 0);
        virtual ~SafeNumber();

        SafeNumber operator / (const IHasNumber & other) const;
        void operator /= (const IHasNumber & other);
        std::ostream & Write(std::ostream &os) const;
        double GetNumber() const override { return val; }

        T val; /// Use any other mathematical function

    protected:

    private:
};

template<class T>
std::ostream &operator<<(std::ostream &os, SafeNumber<T> const &m) {
   return m.Write(os);
}

template<class T>
SafeNumber<T>::SafeNumber(T val) : val(val){}
template<class T>
SafeNumber<T>::~SafeNumber(){}

template<class T>
SafeNumber<T> SafeNumber<T>::operator / (const IHasNumber & other) const
{
    if (other.GetNumber() == 0)
        throw EnjoLib::ExceptRuntimeError("Divison by 0");
    return SafeNumber(val / other.GetNumber());
}

template<class T>
void SafeNumber<T>::operator /= (const IHasNumber & other)
{
    *this = *this / other;
}

template<class T>
std::ostream& SafeNumber<T>::Write(std::ostream& os) const
{
    return os << val;
}

}

#endif // SAFENUMBER_H
