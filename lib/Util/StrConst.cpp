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
    PtrHelper::Copy(m_buf, str, len);
}

const char * StrConst::c_str() const
{
    return m_buf;
}
Str StrConst::String() const
{
    return Str(c_str());
}
