#include "StrColourTest.hpp"
#include <Util/Str.hpp>
#include <Util/StrColour.hpp>
#include <Util/CoutBuf.hpp>

using namespace std;
using namespace EnjoLib;

StrColourTest::~StrColourTest(){}
StrColourTest::StrColourTest()
{
    ELO
    LOG << StrColour::Gen(31, "Czerw") << Endl;
    LOG << StrColour::GenNorm(StrColour::Col::Red, "Czerw") << Endl;
    LOG << StrColour::GenNorm(StrColour::Col::Green, "Ziel") << Endl;
    LOG << StrColour::GenBright(StrColour::ColBright::Green, "ZielJasny") << Endl;
}
