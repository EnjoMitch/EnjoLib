#include <Ios/Ostream.hpp>
#include <STD/Ostream.hpp>

using namespace EnjoLib;
Ostream::Ostream()
{
}

Ostream::~Ostream()
{

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