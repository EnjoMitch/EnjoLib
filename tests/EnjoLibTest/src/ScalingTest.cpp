#include "ScalingTest.h"
#include <Math/GeneralMath.hpp>
#include <Systems/Point.hpp>
#include <Util/Str.hpp>
//#include <Statistical/VecD.hpp>
#include "Math/SplineLin.hpp"
#include <STD/Iostream.hpp>

#include <utility>
#include <Util/Except.hpp>
#include <ctime>

using namespace std;
using namespace EnjoLib;

ScalingTest::ScalingTest(){}
ScalingTest::~ScalingTest(){}

VecD GetRandV(int size)
{
    //VecD in(EnjoLib::VecD {0, 2, 1, 3, 4, 2});
    //VecD in(EnjoLib::VecD {0, 2, 1});
    VecD in;
    for (int i = 0; i < size; ++i)
    {
        double y = (1.0 * rand() / (RAND_MAX));
        in.push_back(y);
    }
    return in;
}

void ScalingTest::Run() const
{
    srand(time(NULL));
    int isizeIn = 15;
    int isizeUp = 25;
    int isizeDown = 10;

    VecD in = GetRandV(isizeIn);
    SplineLin spline(in);
    VecD uppp = spline.Scale(isizeUp);
    VecD down = spline.Scale(isizeDown);


    cout << in.PrintPython("inp");
    cout << uppp.PrintPython("upp");
    cout << down.PrintPython("dow");
}
