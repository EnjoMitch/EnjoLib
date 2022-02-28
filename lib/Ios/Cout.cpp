#include <Ios/Cout.hpp>

#include <STD/Iostream.hpp>

using namespace EnjoLib;

Cout::Cout()
: m_ostream(std::cout)
{
    //ctor
}

Cout::~Cout()
{
    //dtor
}

void Cout::Flush()
{
    m_ostream.flush();
}

std::ostream & Cout::OStr()
{
    return m_ostream;
}
const std::ostream & Cout::OStr() const
{
    return m_ostream;
}
