#include "StrColour.hpp"

#include <STD/Iostream.hpp>
#include <Util/Osstream.hpp>
#include <iomanip>

using namespace std;
using namespace EnjoLib;

const char * StrColour::endTxt = "\033[0m";

StrColour:: StrColour(){}
StrColour::~StrColour(){}

EnjoLib::Str StrColour::GenNorm(float val, int precision)
{
    Osstream oss;
    oss.OStr() << std::setprecision(precision);
    oss.OStr() << std::fixed;
    oss << val;
    
    return GenNorm(val, oss.str());
}
EnjoLib::Str StrColour::GenBright(float val, int precision)
{
    Osstream oss;
    oss.OStr() << std::setprecision(precision);
    oss.OStr() << std::fixed;
    oss << val;
    
    return GenBright(val, oss.str());
}

EnjoLib::Str StrColour::GenErr(const EnjoLib::Str & txt)
{
    return GenNorm(StrColour::Col::Red, txt);
    //return GenBright(StrColour::ColBright::Red, txt);
}

EnjoLib::Str StrColour::GenWarn(const EnjoLib::Str & txt)
{
    return GenNorm(StrColour::Col::Yellow, txt);
}

EnjoLib::Str StrColour::GenNorm(float val, const EnjoLib::Str & txt)
{
    const StrColour::Col col = val > 0 ? StrColour::Col::Green : StrColour::Col::Yellow;
    return GenNorm(col, txt);
}
EnjoLib::Str StrColour::GenBright(float val, const EnjoLib::Str & txt)
{
    const StrColour::ColBright col = val > 0 ? StrColour::ColBright::Green : StrColour::ColBright::Yellow;
    return GenBright(col, txt);
}

EnjoLib::Str StrColour::GenNorm(Col col, const EnjoLib::Str & txt)
{
    return Gen(static_cast<int>(col), txt);
}
EnjoLib::Str StrColour::GenBright(ColBright col, const EnjoLib::Str & txt)
{
    return Gen(static_cast<int>(col), txt);
}

EnjoLib::Str StrColour::Gen(int col, const EnjoLib::Str & str)
{
    return startTxt(col) + str + endTxt;
}

EnjoLib::Str StrColour::startTxt(int col)
{
    return "\x1B[" + std::to_string(col) + "m";
}

/*
Name            FG  BG
Black           30  40
Red             31  41
Green           32  42
Yellow          33  43
Blue            34  44
Magenta         35  45
Cyan            36  46
White           37  47
Bright Black    90  100
Bright Red      91  101
Bright Green    92  102
Bright Yellow   93  103
Bright Blue     94  104
Bright Magenta  95  105
Bright Cyan     96  106
Bright White    97  107
*/

/*
void my()
{
    cout << ColorStr(31, "Texting\t\t") << endl;
    cout << "\x1B[31mTexting\033[0m\t\t" << endl;
    printf("\x1B[31mTexting\033[0m\t\t");
}

void demo()
{
    printf("\n");
    printf("\x1B[31mTexting\033[0m\t\t");
    printf("\x1B[32mTexting\033[0m\t\t");
    printf("\x1B[33mTexting\033[0m\t\t");
    printf("\x1B[34mTexting\033[0m\t\t");
    printf("\x1B[35mTexting\033[0m\n");
    
    printf("\x1B[36mTexting\033[0m\t\t");
    printf("\x1B[36mTexting\033[0m\t\t");
    printf("\x1B[36mTexting\033[0m\t\t");
    printf("\x1B[37mTexting\033[0m\t\t");
    printf("\x1B[93mTexting\033[0m\n");
    
    printf("\033[3;42;30mTexting\033[0m\t\t");
    printf("\033[3;43;30mTexting\033[0m\t\t");
    printf("\033[3;44;30mTexting\033[0m\t\t");
    printf("\033[3;104;30mTexting\033[0m\t\t");
    printf("\033[3;100;30mTexting\033[0m\n");

    printf("\033[3;47;35mTexting\033[0m\t\t");
    printf("\033[2;47;35mTexting\033[0m\t\t");
    printf("\033[1;47;35mTexting\033[0m\t\t");
    printf("\t\t");
    printf("\n");
}
*/
