#include <Ios/Istream.hpp>
#include <Util/Str.hpp>

#include <STD/Istream.hpp>

using namespace EnjoLib;
Istream::Istream()
{
}

Istream::~Istream()
{
}

bool Istream::good() const
{
    return IStr().good();
}

bool Istream::operator !() const
{
    return IStr().fail();
}

Istream::operator bool() const
{
    return not IStr().fail();
}


void Istream::PushVal(long long int * val)
{
    IStr() >> *val;
}

void Istream::PushVal(long long unsigned int * val)
{
    IStr() >> *val;
}

void Istream::PushVal(long unsigned int * val)
{
    IStr() >> *val;
}
void Istream::PushVal(long int * val)
{
    IStr() >> *val;
}
void Istream::PushVal(unsigned int * val)
{
    IStr() >> *val;
}
void Istream::PushVal(int * val)
{
    IStr() >> *val;
}
void Istream::PushVal(bool * val)
{
    IStr() >> *val;
}
void Istream::PushVal(char * val)
{
    IStr() >> *val;
}
void Istream::PushVal(double * val)
{
    IStr() >> *val;
}
void Istream::PushVal(float * val)
{
    IStr() >> *val;
}
void Istream::PushVal(STDFWD::string * val)
{
    IStr() >> *val;
}
void Istream::PushVal(Str * val)
{
    IStr() >> *val;
}

bool EnjoLib::GetLine(Istream& ifs, EnjoLib::Str & lineOut, const char token)
{
    const std::istream & stdis = std::getline(ifs.IStr(), lineOut.strRW(), token);
    if (stdis)
    {
        return true;
    }
    return false;
}
