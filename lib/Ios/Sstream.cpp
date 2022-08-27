#include <Ios/Sstream.hpp>
#include <Util/Str.hpp>
#include <STD/Sstream.hpp>

using namespace EnjoLib;

Sstream::Sstream()
: m_sstream(new std::stringstream())
{}
Sstream::~Sstream(){}

void Sstream::SetStr(const EnjoLib::Str & inp)
{
#ifdef STD_SSTREAM_FINAL
    this->str(inp.str());
#else
    m_sstream->str(inp.str());
#endif
}

#ifndef STD_SSTREAM_FINAL
Str Sstream::ToStr() const
{
    return m_sstream->str();
}

STDFWD::ostream & Sstream::OStr()
{
    return *m_sstream;
}

const STDFWD::ostream & Sstream::OStr() const
{
    return *m_sstream;
}

STDFWD::istream & Sstream::IStr()
{
    return *m_sstream;
}

const STDFWD::istream & Sstream::IStr() const
{
    return *m_sstream;
}
#endif
