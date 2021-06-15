#include <Util/Isstream.hpp>

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

bool Isstream::operator !() const
{
    return m_istream->fail();
}

Isstream::operator bool() const
{
    return not m_istream->fail();
}

stdfwd::istream & Isstream::IStr()
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

void Isstream::PushVal(long unsigned int * val)
{
    *m_istream >> *val;
}
void Isstream::PushVal(unsigned int * val)
{
    *m_istream >> *val;
}
void Isstream::PushVal(int * val)
{
    *m_istream >> *val;
}
void Isstream::PushVal(bool * val)
{
    *m_istream >> *val;
}
void Isstream::PushVal(char * val)
{
    *m_istream >> *val;
}
void Isstream::PushVal(double * val)
{
    *m_istream >> *val;
}
void Isstream::PushVal(float * val)
{
    *m_istream >> *val;
}
void Isstream::PushVal(stdfwd::string * val)
{
    *m_istream >> *val;
}

void Isstream::PushVal(EnjoLib::Str * val)
{
    *m_istream >> *val;
}

bool EnjoLib::GetLine(Isstream& ifs, EnjoLib::Str & lineOut, const char token)
{
    const std::istream & stdis = std::getline(ifs.IStr(), lineOut.strRW(), token);
    if (stdis)
    {
        return true;
    }
    return false;
}
