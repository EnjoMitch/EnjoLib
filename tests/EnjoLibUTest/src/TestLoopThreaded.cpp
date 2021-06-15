#include "pch_test.h"

#include <UnitTest++/UnitTest++.h>
#include <Util/LoopThreaded.hpp>
#include <Template/LoopThreadedTpl.hpp>
#include <Template/VecT.hpp>
#include <Util/VecD.hpp>

#include <STD/Iostream.hpp>

using namespace std;
using namespace EnjoLib;

TEST(LoopThreaded_2)
{
    const int szz = 10;
    const int numCores = 2;
    const LoopThreaded loop(szz, numCores);

    CHECK_EQUAL(0, loop.GetIdxOfDatasetForIteration(0));
    CHECK_EQUAL(1, loop.GetIdxOfDatasetForIteration(9));
}

TEST(LoopThreaded_3)
{
    const int szz = 10;
    const int numCores = 3;
    const LoopThreaded loop(szz, numCores);

    CHECK_EQUAL(0, loop.GetIdxOfDatasetForIteration(0));
    CHECK_EQUAL(1, loop.GetIdxOfDatasetForIteration(5));
    CHECK_EQUAL(2, loop.GetIdxOfDatasetForIteration(9));
}

static double Conv(const int & aaa)
{
    const double out = aaa / 10.0;
    return out;
}

TEST(LoopThreaded_hi1)
{
    EnjoLib::VecT<int> lines;
    for (int i = 0; i < 50; ++i)
    {
        lines.push_back(i);
    }
    std::function<decltype(Conv)> f_conv = &Conv;
    const EnjoLib::VecD & out = ConvertVectorThreaded2(lines, f_conv);
    const EnjoLib::VecD & out1 = ConvertVectorThreaded2(lines, f_conv, 1);
    EnjoLib::VecD out2;
    for (int i = 0; i < int(lines.size()); ++i)
    {
        out2.push_back(Conv(lines.at(i)));
    }
    CHECK(out == out2);
    CHECK(out == out1);
}
