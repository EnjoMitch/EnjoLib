#include <Ios/Cin.hpp>

#include <STD/Iostream.hpp>

using namespace EnjoLib;

Cin::Cin()
: m_istream(std::cin)
{
}

Cin::~Cin(){}

std::istream & Cin::IStr()
{
    return m_istream;
}
const std::istream & Cin::IStr() const
{
    return m_istream;
}
