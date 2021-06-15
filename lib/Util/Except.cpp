#include <Util/Except.hpp>

using namespace EnjoLib;

Except::Except(const Str & msg)
: std::exception()
, m_msg(msg)
{
    //ctor
}

Except::~Except()
{
    //dtor
}

const char * Except::what() const noexcept
{
    return m_msg.c_str();
}