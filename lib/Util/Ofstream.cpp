#include "Ofstream.hpp"
#include <Util/Except.hpp>
//#include <Util/CoutBuf.hpp>
#include <STD/Fstream.hpp>
#include <STD/Sstream.hpp>

using namespace std;
using namespace EnjoLib;

/*
Ofstream::~Ofstream(){}
Ofstream::Ofstream(const EnjoLib::Str& fileName, bool tryOpen)
//: m_stream(new ofstream(fileName.c_str()))
: ofstream(fileName.c_str())
, m_fileName(fileName)
{
    if (tryOpen)
        IsOpenThrow();
}
*/

Ofstream::Ofstream(const EnjoLib::Str& fileName, bool tryOpen)
: m_ostream(new ostringstream())
, m_ofstream(new std::ofstream(fileName.c_str()))
, m_fileName(fileName)
{
    if (tryOpen)
        IsOpenThrow();
}
Ofstream::~Ofstream()
{
    if (is_open())
    {
        *m_ofstream << m_ostream->str();
        //m_ofstream->flush();
    }
}

void Ofstream::IsOpenThrow() const
{
    //if (! m_stream->is_open())
    if (! is_open())
    {
        throw EnjoLib::ExceptRuntimeError("Couldn't open '" + m_fileName + "' for writing!");
    }
    else
    {
        //std::cout << "Opened '" + m_fileName + "' for writing.\n";
    }
}

EnjoLib::Str Ofstream::Str() const
{
    return m_ostream->str();
}

void Ofstream::Add(const EnjoLib::Str & str)
{
    *m_ostream << str.str();
}

void Ofstream::flush()
{
    m_ostream->flush();
}


bool Ofstream::is_open() const
{
    return m_ofstream->is_open();
}

stdfwd::ostream & Ofstream::OStr()
{
    return *m_ostream;
}

void Ofstream::AddVal(double val)
{
    *m_ostream << val;
}

void Ofstream::AddVal(int val)
{
    *m_ostream << val;
}

void Ofstream::AddVal(char val)
{
    *m_ostream << val;
}

void Ofstream::AddVal(long unsigned int val)
{
    *m_ostream << val;
}

void Ofstream::AddVal(unsigned int val)
{
    *m_ostream << val;
}

void Ofstream::AddVal(const char * val)
{
    Add(val);
}

void Ofstream::AddVal(const std::string & val)
{
    Add(val);
}
