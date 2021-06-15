#include "Ifstream.hpp"
#include <Util/Except.hpp>
//#include <Util/CoutBuf.hpp>
#include <STD/Fstream.hpp>
#include <Util/Osstream.hpp>

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


bool Ifstream::operator !() const
{
    return m_ifstream->fail();
}

bool Ifstream::is_open() const
{
    return m_ifstream->is_open();
}

void Ifstream::close()
{
    m_ifstream->close();
}

stdfwd::istream & Ifstream::IStr()
{
    return *m_ifstream;
}

void Ifstream::PushVal(long unsigned int * val)
{
    *m_ifstream >> *val;
}
void Ifstream::PushVal(unsigned int * val)
{
    *m_ifstream >> *val;
}
void Ifstream::PushVal(int * val)
{
    *m_ifstream >> *val;
}
void Ifstream::PushVal(bool * val)
{
    *m_ifstream >> *val;
}
void Ifstream::PushVal(char * val)
{
    *m_ifstream >> *val;
}
void Ifstream::PushVal(double * val)
{
    *m_ifstream >> *val;
}
void Ifstream::PushVal(float * val)
{
    *m_ifstream >> *val;
}
void Ifstream::PushVal(stdfwd::string * val)
{
    *m_ifstream >> *val;
}

bool EnjoLib::GetLine(Ifstream& ifs, EnjoLib::Str & lineOut)
{
    const std::istream & stdis = std::getline(ifs.IStr(), lineOut.strRW());
    if (stdis)
    {
        return true;
    }
    return false;
}

#endif // IFSTREAM_NEW
