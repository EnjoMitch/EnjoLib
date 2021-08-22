#include <Ios/Ostream.hpp>
#include <STD/Ostream.hpp>
#include <STD/Iomanip.hpp>

using namespace EnjoLib;
Ostream::Ostream(){}
Ostream::~Ostream(){}

Ostream & Ostream::SetPrecision(int prec)
{
    OStr() << std::setprecision(prec);
    return *this;
}

Ostream & Ostream::SetW(int width)
{
    OStr() << std::setw(width);
    return *this;
}

Ostream & Ostream::SetFill(char toFill)
{
    OStr() << std::setfill(toFill);
    return *this;
}

Ostream & Ostream::Fixed()
{
    std::fixed(OStr());
    return *this;
}

Ostream & Ostream::Scientific()
{
    std::scientific(OStr());
    return *this;
}


void Ostream::AddVal(double val)
{
    OStr() << val;
}

void Ostream::AddVal(long int val)
{
    OStr() << val;
}

void Ostream::AddVal(int val)
{
    OStr() << val;
}

void Ostream::AddVal(char val)
{
    OStr() << val;
}

void Ostream::AddVal(long unsigned int val)
{
    OStr() << val;
}

void Ostream::AddVal(long long unsigned int val)
{
    OStr() << val;
}

void Ostream::AddVal(unsigned int val)
{
    OStr() << val;
}

void Ostream::AddVal(const char * val)
{
    //Add(val);
    OStr() << val;
}

void Ostream::AddVal(const std::string & val)
{
    //Add(val);
    OStr() << val;
}

void Ostream::AddVal(const EnjoLib::Str & val)
{
    //Add(val);
    OStr() << val;
}

/*
void Osstream::Add(const EnjoLib::Str & str)
{
    *m_ostream << str.str();
}

void Osstream::AddVal(const EnjoLib::Str & str)
{
    Add(str);
}
*/