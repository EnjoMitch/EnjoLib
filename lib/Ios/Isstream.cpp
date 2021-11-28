#include <Ios/Isstream.hpp>

#include <STD/Sstream.hpp>

using namespace std;
using namespace EnjoLib;

Isstream::~Isstream(){}
Isstream::Isstream(const EnjoLib::Str & inp)
: m_istream(new istringstream())
{
    if (not inp.empty())
    {
        m_istream->str(inp.c_str());
    }
}

const STDFWD::istream & Isstream::IStr() const
{
    return *m_istream;
}

STDFWD::istream & Isstream::IStr()
{
    return *m_istream;
}

void Isstream::str(const EnjoLib::Str & inp)
{
    m_istream->str(inp.c_str());
}

EnjoLib::Str Isstream::str() const
{
    return m_istream->str();
}
