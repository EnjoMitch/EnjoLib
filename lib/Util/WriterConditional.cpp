#include "WriterConditional.hpp"

using namespace EnjoLib;

WriterConditional::WriterConditional(EnjoLib::Ostream & ostr, bool shouldWrite)
: m_shouldWrite(shouldWrite)
, m_ostr(ostr)
{
}

WriterConditional::~WriterConditional(){}

void WriterConditional::Write(const EnjoLib::Str & text)
{
    if (m_shouldWrite)
    {
        m_ostr << text;
    }
}