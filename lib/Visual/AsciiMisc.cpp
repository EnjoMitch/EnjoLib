#include <Visual/AsciiMisc.hpp>

#include <Util/Str.hpp>
#include <Util/CoutBuf.hpp>
#include <Math/GeneralMath.hpp>

using namespace EnjoLib;

size_t AsciiMisc::EraseLineGetPrevSize(const EnjoLib::Str & str, size_t prevSize) const
{
    EnjoLib::Cout out;
    for (size_t i = 0; i < prevSize; ++i)
        out << '\b'; // Move back
    for (size_t i = 0; i < prevSize; ++i)
        out << ' ';  // Erase by filling with spaces
    for (size_t i = 0; i < prevSize; ++i)
        out << '\b'; // Move back again for the next printout

    out << str;
    out.Flush();
    return str.size();
}

Str AsciiMisc::GenBars10(double percentage, const char barFull, const char barEmpty) const
{
    const Str tagStart = "[";
    const Str tagEnd   = "]";
    const Str tagOn    = barFull;
    const Str tagOff   = barEmpty;

    const int numBars = 10;

    int percentage0_10 = int(GMat().round(percentage / 10.0));
    if (percentage0_10 > numBars)
    {
        percentage0_10 = numBars;
    }
    if (percentage0_10 < 0)
    {
        percentage0_10 = 0;
    }
    Osstream oss;
    oss << tagStart;
    oss << GenChars(tagOn,  percentage0_10);
    oss << GenChars(tagOff, numBars - percentage0_10);
    oss << tagEnd;
    return oss.str();
}

Str AsciiMisc::GenChars(const Str & pattern, int numberOfRepetitions) const
{
    Osstream oss;
    for (int i = 0; i < numberOfRepetitions; ++i)
    {
        oss << pattern;
    }
    return oss.str();
}
