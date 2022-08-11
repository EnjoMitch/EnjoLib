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

static void Promo(const VecD & data);
TEST(Distrib_prmo)
{
    const VecD & data = GenDistribData();
    //Promo(data);
}
void Promo(const VecD & data)
{
    ELO
    const Distrib distr;
    const DistribData & distData = distr.GetDistrib(data, 31);
    LOG << "Promo:\n\n";
    //cout << "Cov size = " << cov.SizeStr() << endl;
    const Str & retP = distr.PlotLine(distData, true, true, false);
    LOG << Nl << Nl;
    LOG << StrColour::GenNorm(StrColour::Col::Green, retP) << Nl;
    LOG << "\t    Status is" << Nl << StrColour::GenBright(StrColour::ColBright::Green, 
           "\t     GREEN!") << Nl;
    LOG << Nl << Nl << Nl;
}
