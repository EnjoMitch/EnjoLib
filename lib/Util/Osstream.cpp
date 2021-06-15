#include <Util/Osstream.hpp>

#include <STD/Sstream.hpp>

using namespace std;
using namespace EnjoLib;

Osstream::Osstream()
: m_ostream(new ostringstream())
{
}
Osstream::~Osstream(){}

EnjoLib::Str Osstream::Str() const
{
    return m_ostream->str();
}

EnjoLib::Str Osstream::str() const
{
    return m_ostream->str();
}

void Osstream::Add(const EnjoLib::Str & str)
{
    *m_ostream << str.str();
}

void Osstream::AddVal(const EnjoLib::Str & str)
{
    Add(str);
}

stdfwd::ostream & Osstream::OStr()
{
    return *m_ostream;
}

void Osstream::AddVal(double val)
{
    *m_ostream << val;
}

void Osstream::AddVal(long int val)
{
    *m_ostream << val;
}

void Osstream::AddVal(int val)
{
    *m_ostream << val;
}

void Osstream::AddVal(char val)
{
    *m_ostream << val;
}

void Osstream::AddVal(long unsigned int val)
{
    *m_ostream << val;
}

void Osstream::AddVal(unsigned int val)
{
    *m_ostream << val;
}

void Osstream::AddVal(const char * val)
{
    Add(val);
}

void Osstream::AddVal(const std::string & val)
{
    Add(val);
}
