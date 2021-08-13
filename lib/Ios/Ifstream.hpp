#ifndef IFSTREAM_H
#define IFSTREAM_H

#include <Ios/Istream.hpp>
#include <Util/Str.hpp>
#include <Template/SafePtr.hpp>

#define IFSTREAM_NEW

namespace EnjoLib
{
#ifndef IFSTREAM_NEW

#include <STD/Istream.hpp>
#include <Ios/Ofstream.hpp>
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
class Ifstream : public Istream
{
    public:
        Ifstream(const EnjoLib::Str & fileName, bool tryOpen = true);
        virtual ~Ifstream();

        const EnjoLib::Str & GetFileName() const { return m_fileName; }
        void IsOpenThrow() const;
        
        stdfwd::istream & IStr() override;
        const stdfwd::istream & IStr() const override;
        
        bool is_open() const;
        void close();
    
    protected:

    private:
        SafePtr<std::ifstream> m_ifstream;
        //SafePtr<std::istringstream> m_istream;
        const EnjoLib::Str m_fileName;
};

#endif // IFSTREAM_NEW
}

#endif // IFSTREAM_H
