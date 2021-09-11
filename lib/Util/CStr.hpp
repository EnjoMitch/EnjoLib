#ifndef CSTR_H
#define CSTR_H

#include "Str.hpp"
#include <Util/CharManipulations.hpp>

template <class T>
static EnjoLib::Str ToStr(const T & t, char sep = '|')
{
    const EnjoLib::CharManipulations cman;
    return cman.ToStr(t) + sep;
}

class CStr
{
    public:
        CStr(char sep = '|');

        template <class T>
        EnjoLib::Str operator() (const T & t) const
        {
            return EnjoLib::Str(t, m_sep);
        }

    private:
        char m_sep = 0;

};

#endif // CSTR_H
