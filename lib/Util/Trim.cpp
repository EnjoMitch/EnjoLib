#include "Trim.hpp"

#include <STD/Algorithm.hpp>
#include <functional>
#include <cctype>
#include <locale>


using namespace std;
using namespace EnjoLib;

// trim from start
EnjoLib::Str & Trim::ltrim(EnjoLib::Str &ss) const
{
        string & s = ss.strRW();
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return ss;
}

// trim from end
EnjoLib::Str & Trim::rtrim(EnjoLib::Str &ss) const
{
    string & s = ss.strRW();
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return ss;
}

// trim from both ends
EnjoLib::Str & Trim::trim(EnjoLib::Str &ss)  const
{
        return ltrim(rtrim(ss));
}
