#ifndef ISTREAM_1_HPP
#define ISTREAM_1_HPP

#include <Ios/IosBase.hpp>
#include <Util/Str.hpp>
#include <3rdParty/stdfwd.hh>

namespace EnjoLib {
class Istream
{
    public:
        Istream();
        virtual ~Istream();

        virtual STDFWD::istream & IStr() = 0;
        virtual const STDFWD::istream & IStr() const = 0;

        bool good() const;
        bool operator !() const;
        operator bool() const;

        template <class T> friend Istream& operator >> (Istream&, T & val);

    protected:
        void PushVal(long long unsigned int * val);
        void PushVal(long unsigned int * val);
        void PushVal(long int * val);
        void PushVal(unsigned int * val);
        void PushVal(int * val);
        void PushVal(bool * val);
        void PushVal(char * val);
        void PushVal(double * val);
        void PushVal(float * val);
        void PushVal(STDFWD::string * val);
        void PushVal(EnjoLib::Str * val);

    private:
};

bool GetLine(Istream& ifs, EnjoLib::Str & lineOut, const char token = '\n');

template <class T> Istream& operator >> (Istream& ifst, T & val)
{
    ifst.PushVal(&val);
    return ifst;
}

}

#endif // ISTREAM_HPP
