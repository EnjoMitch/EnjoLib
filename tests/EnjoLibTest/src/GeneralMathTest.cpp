#include "GeneralMathTest.h"
#include <Math/GeneralMath.hpp>
#include <Util/CoutBuf.hpp>

using namespace EnjoLib;
using namespace std;

GeneralMathTest::GeneralMathTest()
{
    const GeneralMath gmat;
    for (double x = -4; x <= 4; x += 1)
    {
        LOGL << "x, y = " << x << ", " << gmat.PointsPower(x, 2) << Endl;
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
