#include "GeneralMathTest.h"
#include <Math/GeneralMath.hpp>

#include <STD/Iostream.hpp>

using namespace EnjoLib;
using namespace std;

GeneralMathTest::GeneralMathTest()
{
    const GeneralMath gmat;
    for (double x = -4; x <= 4; x += 1)
    {
        cout << "x, y = " << x << ", " << gmat.PointsPower(x, 2) << endl;
    }

    for (int i = 0; i < 100; ++i)
    {
        //cout << GeneralMath().Rand(-1, 2) << endl;
    }
}

GeneralMathTest::~GeneralMathTest()
{
    //dtor
}
