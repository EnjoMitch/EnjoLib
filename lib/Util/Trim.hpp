#ifndef TRIM_H
#define TRIM_H

#include <Util/Str.hpp>

namespace EnjoLib
{
class Trim
{
    public:
        EnjoLib::Str & ltrim(EnjoLib::Str &s) const;
        EnjoLib::Str & rtrim(EnjoLib::Str &s) const;
        EnjoLib::Str & trim(EnjoLib::Str &s) const;
    protected:
    private:
};
}

#endif // TRIM_H
