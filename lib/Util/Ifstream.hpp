#ifndef IFSTREAM_H
#define IFSTREAM_H

#include <Util/Str.hpp>
#include <Template/SafePtr.hpp>

#define IFSTREAM_NEW

namespace EnjoLib
{
#ifndef IFSTREAM_NEW

#include <STD/Istream.hpp>
#include <Util/Ofstream.hpp>
class Ifstream : public std::ifstream
{
    public:
        Ifstream(const EnjoLib::Str & fileName, bool tryOpen = true);
        virtual ~Ifstream();

        const EnjoLib::Str & GetFileName() const { return m_fileName; }
        void IsOpenThrow() const;
    protected:

    private:
        //SafePtr<std::ifstream> m_stream;
        const EnjoLib::Str m_fileName;
};
#else
class Ifstream
{
    public:
        Ifstream(const EnjoLib::Str & fileName, bool tryOpen = true);
        virtual ~Ifstream();

        const EnjoLib::Str & GetFileName() const { return m_fileName; }
        void IsOpenThrow() const;
        
        stdfwd::istream & IStr();
        
        bool is_open() const;
        void close();
        
        bool operator !() const;
        
        template <class T> friend Ifstream& operator >> (Ifstream&, T & val);
        
        void PushVal(long long unsigned int * val);
        void PushVal(long unsigned int * val);
        void PushVal(unsigned int * val);
        void PushVal(int * val);
        void PushVal(bool * val);
        void PushVal(char * val);
        void PushVal(double * val);
        void PushVal(float * val);
        void PushVal(stdfwd::string * val);

    protected:

    private:
        SafePtr<std::ifstream> m_ifstream;
        //SafePtr<std::istringstream> m_istream;
        const EnjoLib::Str m_fileName;
};

bool GetLine(Ifstream& ifs, EnjoLib::Str & lineOut);

template <class T> Ifstream& operator >> (Ifstream& ifst, T & val)
{
    ifst.PushVal(&val);
    return ifst;
}

#endif // IFSTREAM_NEW
}

#endif // IFSTREAM_H
