#include <Ios/Ostream.hpp>
#include <STD/Ostream.hpp>

using namespace EnjoLib;
Ostream::Ostream(){}
Ostream::~Ostream(){}

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
    AddStr(val);
}

void Ostream::AddVal(const std::string & val)
{
    AddStr(val);
}

void Ostream::AddVal(const EnjoLib::Str & val)
{
    //Add(val);
    AddStr(val.str());
}

void Ostream::AddStr(const STDFWD::string & val)
{
    if (val == Endl) /// TODO: This doesn't really work for LOGL macro - it doesn't prune the line, only at the desctructor.
    {
        OStr() << std::endl;
    }
    else
    {
        //Add(val);
        OStr() << val;
    }
}

void Ostream::AddVal(const Ostream & ostr)
{

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
