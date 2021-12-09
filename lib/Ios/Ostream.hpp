#ifndef OSTREAM_1_H
#define OSTREAM_1_H

#include <Ios/IosBase.hpp>
#include <Util/Str.hpp>
#include <3rdParty/stdfwd.hh>

namespace EnjoLib {
class Ostream
{
    public:
        Ostream();
        virtual ~Ostream();

        virtual STDFWD::ostream & OStr() = 0;
        virtual const STDFWD::ostream & OStr() const = 0;

        template <class T> Ostream& operator << (const T & val);

    protected:
        void AddVal(long unsigned int val);
        void AddVal(long long unsigned int val);
        void AddVal(long long int val);
        void AddVal(long int val);
        void AddVal(unsigned int val);
        void AddVal(int val);
        void AddVal(char val);
        void AddVal(double val);
        void AddVal(const char * val);
        void AddVal(const STDFWD::string & val);
        void AddVal(const EnjoLib::Str & str);
        void AddVal(const Ostream & ostr);

    private:
        void AddStr(const STDFWD::string & val);
};

template <class T> Ostream& Ostream::operator << (const T & val)
{
    this->AddVal(val);
    return *this;
}
}
#endif // OSTREAM_H
