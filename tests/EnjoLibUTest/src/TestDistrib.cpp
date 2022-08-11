#include "pch_test.h"

#include <Util/VecD.hpp>
#include <Util/CoutBuf.hpp>
#include <Util/StrColour.hpp>
#include <Statistical/Distrib.hpp>
#include <Math/RandomMath.hpp>

#include <UnitTest++/UnitTest++.h>

using namespace std;
using namespace EnjoLib;

static VecD GenDistribData()
{
    VecD data;
    const RandomMath rmath;
    for (int i = 0; i < 2e4; ++i) data.push_back(rmath.SampleNormal());
    return data;
}

TEST(Distrib_test_plot)
{
    ELO
    const Distrib distr;
    const VecD & data = GenDistribData();
    
    const DistribData & distData = distr.GetDistrib(data, 40);

    const Str & ret1 = distr.PlotLine(distData, true, false);
    const Str & ret2 = distr.PlotLine(distData, false, true);
    const Str & ret3 = distr.PlotLine(distData, false, false, false);
    CHECK(ret1.size());
    CHECK(ret2.size());
    CHECK(ret3.size());

    LOG << ret1 << Nl;
    LOG << ret2 << Nl;
    LOG << ret3 << Nl;
}
