#include "ScalingTest.h"
#include <Math/RandomMath.hpp>
#include <Systems/Point.hpp>
#include <Util/Str.hpp>
//#include <Statistical/VecD.hpp>
#include "Math/SplineLin.hpp"
#include <Util/CoutBuf.hpp>

#include <Util/Pair.hpp>
#include <Util/Except.hpp>
//#include <ctime>

using namespace std;
using namespace EnjoLib;

ScalingTest::ScalingTest(){}
ScalingTest::~ScalingTest(){}

VecD GetRandV(int size)
{
    const RandomMath rmat;
    //VecD in(EnjoLib::VecD {0, 2, 1, 3, 4, 2});
    //VecD in(EnjoLib::VecD {0, 2, 1});
    VecD in;
    for (int i = 0; i < size; ++i)
    {
        double y = rmat.Rand(0, 1.0);
        in.push_back(y);
    }
    return in;
}

void ScalingTest::Run() const
{
    ELO
    const RandomMath rmat;
    rmat.RandSeed();
    int isizeIn = 15;
    int isizeUp = 25;
    int isizeDown = 10;

    VecD in = GetRandV(isizeIn);
    SplineLin spline(in);
    VecD uppp = spline.Scale(isizeUp);
    VecD down = spline.Scale(isizeDown);


    LOG << in.PrintPython("inp");
    LOG << uppp.PrintPython("upp");
    LOG << down.PrintPython("dow");
}
