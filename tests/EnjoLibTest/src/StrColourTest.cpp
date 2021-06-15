#include "StrColourTest.hpp"
#include <Util/StrColour.hpp>
#include <STD/Iostream.hpp>

using namespace std;
using namespace EnjoLib;

StrColourTest::~StrColourTest(){}
StrColourTest::StrColourTest()
{
    cout << StrColour::Gen(31, "Czerw") << endl;
    cout << StrColour::GenNorm(StrColour::Col::Red, "Czerw") << endl;
    cout << StrColour::GenNorm(StrColour::Col::Green, "Ziel") << endl;
    cout << StrColour::GenBright(StrColour::ColBright::Green, "ZielJasny") << endl;
}
