#include "pch_test.h"

#include <Util/VecD.hpp>
#include <Util/CoutBuf.hpp>
#include <Statistical/Distrib.hpp>
#include <Math/RandomMath.hpp>

#include <UnitTest++/UnitTest++.h>

using namespace std;
using namespace EnjoLib;

TEST(Distrib_test_plot)
{
    ELO
    const RandomMath rmath;
    const Distrib distr;

    VecD data;
    for (int i = 0; i < 2e4; ++i)
    {
        data.push_back(rmath.SampleNormal());
    }
    const DistribData & distData = distr.GetDistrib(data, 40);

    const Str & ret1 = distr.PlotLine(distData, true, false);
    const Str & ret2 = distr.PlotLine(distData, false, true);
    const Str & ret3 = distr.PlotLine(distData, false, false);
    CHECK(ret1.size());
    CHECK(ret2.size());
    CHECK(ret3.size());


    LOG << ret1 << Nl;
    LOG << ret2 << Nl;
    LOG << ret3 << Nl;

    //cout << "Cov size = " << cov.SizeStr() << endl;
}
