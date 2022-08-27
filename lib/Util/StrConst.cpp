#include <Util/StrConst.hpp>
#include <Util/Str.hpp>
#include <Template/PtrHelper.hpp>

#include <cstring>

using namespace EnjoLib;

StrConst::StrConst()
{
    Init("");
}

StrConst::StrConst(const char * str)
{
    Init(str);
}

StrConst::StrConst(const Str & str)
{
    Init(str.c_str());
}

StrConst::~StrConst(){}

void StrConst::Init(const char * str)
{
    //const int len = std::strlen(m_buf);
    const int len = sizeof(m_buf);
    memset(m_buf, 0, len);
    
    if (str != nullptr)
    {
        const Str sanitized(str);
        const char * cstr = sanitized.c_str();
        PtrHelper::Copy(m_buf, cstr, len);
    }
}

const char * StrConst::c_str() const
{
    return m_buf;
}
Str StrConst::String() const
{
    return Str(c_str());
}

Str StrConst::str() const
{
    return String();
}
