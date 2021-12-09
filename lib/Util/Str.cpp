#include "Str.hpp"
#include "StrImpl.hpp"

#include <Ios/Ofstream.hpp>
#include <Ios/Ifstream.hpp>

//#include <wstring>

using namespace EnjoLib;

Str::~Str(){}
Str::Str():                 Str(std::string()){}
Str::Str(const Str & str):  Str(str.str()){}
Str::Str(const char crr): Str(std::string(1, crr)) {}
Str::Str(const char * str): Str(std::string(str)) {}
Str::Str(const wchar_t * str): Str(std::string())
{
    const std::wstring wstr(str);
    // your new String
    const std::string bstr(wstr.begin(), wstr.end());
    // Show String
    strRW() = bstr;
    /// TODO: This is plain wrong and assumes, that the incoming parameter is standard ASCII, not the extended one.
    // https://stackoverflow.com/questions/27720553/conversion-of-wchar-t-to-string
}
Str::Str(size_t num, const char crr): Str(std::string(num, crr)) {}

Str::Str(const std::string & str)
: m_pimp(new StrImpl(str))
{
    //ctor
}


void Str::pimpl_deleter::operator()(StrImpl*ptr) const { delete ptr; }

Str & Str::operator=(const Str & str)
{
    strRW() = str.str();
    return *this;
}

const char * Str::c_str() const
{
    return m_pimp->dat.c_str();
}
std::string Str::str() const
{
    return m_pimp->dat;
}
std::string & Str::strRW()
{
    return m_pimp->dat;
}
const std::string & Str::strRef() const
{
    return m_pimp->dat;
}

size_t Str::size() const
{
    return m_pimp->dat.size();
}

size_t Str::length() const
{
    return size();
}

bool Str::empty() const
{
    return m_pimp->dat.empty();
}

const char & Str::at(size_t i) const
{
    return m_pimp->dat.at(i);
}

char & Str::at(size_t i)
{
    return m_pimp->dat.at(i);
}

const char & Str::operator[](size_t i) const
{
    return at(i);
}

char & Str::operator[](size_t i)
{
    return at(i);
}

void Str::pop_back()
{
    m_pimp->dat.pop_back();
}

const char & Str::front() const
{
    return at(0);
}
char & Str::front()
{
    return at(0);
}
const char & Str::back() const
{
    return at(size()-1);
}
char & Str::back()
{
    return at(size()-1);
}

EnjoLib::Str  EnjoLib::operator+ (const EnjoLib::Str& str, const EnjoLib::Str& strOther)
{
    return str.str() + strOther.str();
}

EnjoLib::Str&  EnjoLib::operator+= (EnjoLib::Str& str, const EnjoLib::Str& strOther)
{
    str.strRW() += strOther.str();
    return str;
}

std::ostream& EnjoLib::operator<<(std::ostream& os, const EnjoLib::Str& str)
{
    os << str.str();
    return os;
}

std::istream& EnjoLib::operator>>(std::istream& os, EnjoLib::Str& str)
{
    os >> str.strRW();
    return os;
}

bool  EnjoLib::operator== (const EnjoLib::Str& str, const EnjoLib::Str& strOther)
{
    return str.str() == strOther.str();
}

bool  EnjoLib::operator!= (const EnjoLib::Str& str, const EnjoLib::Str& strOther)
{
    return str.str() != strOther.str();
}

bool  EnjoLib::operator< (const EnjoLib::Str& str, const EnjoLib::Str& strOther)
{
    return str.str() < strOther.str();
}
