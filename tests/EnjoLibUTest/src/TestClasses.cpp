#include "TestClasses.h"

#include <Util/CharManipulations.hpp>

const EnjoLib::Str & Sym::GetName() const
{
    return m_name;
}

Sym::Sym(const EnjoLib::Str & name)
: m_name(EnjoLib::CharManipulations().ToLower(name))
, m_nameCurPrefix(EnjoLib::CharManipulations().Trim(GetName()).str())
{

}
