#ifndef IFSTREAM_H
#define IFSTREAM_H

#include <Ios/Istream.hpp>
#include <Util/StrConst.hpp>
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
        Ifstream(const EnjoLib::StrConst & fileName, bool tryOpen = true);
        virtual ~Ifstream();

        const EnjoLib::StrConst & GetFileName() const { return m_fileName; }
        void IsOpenThrow() const;
    protected:

    private:
        //SafePtr<std::ifstream> m_stream;
        const EnjoLib::StrConst m_fileName;
};
#else
class Ifstream : public Istream
{
    public:
        Ifstream(const EnjoLib::StrConst & fileName, bool tryOpen = true);
        virtual ~Ifstream();

        const EnjoLib::StrConst & GetFileName() const { return m_fileName; }
        void IsOpenThrow() const;

        STDFWD::istream & IStr() override;
        const STDFWD::istream & IStr() const override;

        bool is_open() const;
        void close();

    protected:

    private:
        SafePtr<std::ifstream> m_ifstream;
        //SafePtr<std::istringstream> m_istream;
        const EnjoLib::StrConst m_fileName;
};

#endif // IFSTREAM_NEW
}

#endif // IFSTREAM_H
