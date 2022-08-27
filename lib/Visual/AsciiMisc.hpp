#ifndef ASCIIMISC_HPP
#define ASCIIMISC_HPP

#include <Util/StrFwd.hpp>
#include <cstdlib>

namespace EnjoLib {
class AsciiMisc
{
public:
    size_t EraseLineGetPrevSize(const EnjoLib::Str & str, size_t prevSize) const;
    Str GenBars10(double percentage0_100, const char barFull = '=', const char barEmpty = ' ') const;
    Str GenChars(const Str & pattern, int numberOfRepetitions) const;

private:
};
}

#endif // ASCIIMISC_HPP
