#ifndef OFSTREAM_H
#define OFSTREAM_H

#include <Util/Str.hpp>
#include <Template/SafePtr.hpp>

//#include <ostream>
//#include <Util/Ofstream.hpp>

namespace EnjoLib
{
/*
class Ofstream : public std::ofstream
{
    public:
        explicit Ofstream(const EnjoLib::Str & fileName, bool tryOpen = true);
        virtual ~Ofstream();

        const EnjoLib::Str & GetFileName() const { return m_fileName; }
        void IsOpenThrow() const;
        //bool is_open() const;

    protected:

    private:
        //SafePtr<std::ofstream> m_stream;
        const EnjoLib::Str m_fileName;
};
*/
class Ofstream
{
    public:
        explicit Ofstream(const EnjoLib::Str & fileName, bool tryOpen = true);
        virtual ~Ofstream();

        const EnjoLib::Str & GetFileName() const { return m_fileName; }
        void IsOpenThrow() const;
        bool is_open() const;
        void flush();
        
        stdfwd::ostream & OStr();
        
        EnjoLib::Str Str() const;
        void Add(const EnjoLib::Str & str); // TODO: Remove?
        
        // AddVal avoids auto conversions to Str(char)
        void AddVal(long unsigned int val);
        void AddVal(unsigned int val);
        void AddVal(int val);
        void AddVal(char val);
        void AddVal(double val);
        void AddVal(const char * val);
        void AddVal(const stdfwd::string & val);
        
        template <class T> Ofstream& operator << (const T & val);
        
        //friend EnjoLib::Ofstream& operator<<(EnjoLib::Ofstream& os,  const stdfwd::istream & istr);

    protected:

    private:
        SafePtr<std::ostringstream> m_ostream;
        SafePtr<std::ofstream> m_ofstream;
        const EnjoLib::Str m_fileName;
};

template <class T> Ofstream& Ofstream::operator << (const T & val)
{
    this->AddVal(val);
    return *this;
}

const char NL = '\n';
}

#endif // OFSTREAM_H
