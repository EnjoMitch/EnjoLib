#include <Ios/Osstream.hpp>
#include <Util/Str.hpp>

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

const STDFWD::ostream & Osstream::OStr() const
{
    return *m_ostream;
}

STDFWD::ostream & Osstream::OStr()
{
    return *m_ostream;
}

void Osstream::Clear()
{
    m_ostream->str("");
}