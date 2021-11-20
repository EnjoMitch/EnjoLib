#include <Ios/Ifstream.hpp>

#include <Ios/Osstream.hpp>
#include <Util/Except.hpp>
//#include <Util/CoutBuf.hpp>

#include <STD/Fstream.hpp>

using namespace std;
using namespace EnjoLib;

void Ifstream::IsOpenThrow() const
{
    //if (! m_stream->is_open())
    if (! is_open())
    {
        throw EnjoLib::ExceptRuntimeError("Couldn't open '" + m_fileName.str() + "' for reading!");
    }
}

#ifndef IFSTREAM_NEW
Ifstream::Ifstream(const EnjoLib::Str& fileName, bool tryOpen)
//: m_stream(new ifstream(fileName.c_str()))
: ifstream(fileName.c_str())
, m_fileName(fileName)
{
    if (tryOpen)
        IsOpenThrow();
}

Ifstream::~Ifstream(){}

#else

Ifstream::Ifstream(const EnjoLib::Str& fileName, bool tryOpen)
: m_ifstream(new ifstream(fileName.c_str()))
//, m_istream(new istringstream())
, m_fileName(fileName)
{
    if (tryOpen)
        IsOpenThrow();
}

Ifstream::~Ifstream(){}

bool Ifstream::is_open() const
{
    return m_ifstream->is_open();
}

void Ifstream::close()
{
    m_ifstream->close();
}

const stdfwd::istream & Ifstream::IStr() const
{
    return *m_ifstream;
}

stdfwd::istream & Ifstream::IStr()
{
    return *m_ifstream;
}

#endif // IFSTREAM_NEW
