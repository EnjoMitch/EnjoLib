#ifndef CSTR_H
#define CSTR_H

#include "Str.hpp"
#include <STD/String.hpp>

template <class T>
static EnjoLib::Str ToStr(const T & t, char sep = '|')
{
    return std::to_string(t) + sep;
}

class CStr
{
    public:
        CStr(char sep = '|');

        template <class T>
        EnjoLib::Str operator() (const T & t) const
        {
            return EnjoLib::Str(t, m_sep).str();
        }

    private:
        char m_sep = 0;

};

#endif // CSTR_H
