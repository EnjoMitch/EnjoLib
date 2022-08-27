#include "AnimationTest.h"

#include <Util/ProgressMonitHigh.hpp>
#include <Util/ThreadWrap.hpp>
#include <Util/CoutBuf.hpp>
#include <Util/VecD.hpp>
#include <Visual/AsciiMisc.hpp>
#include <Visual/AsciiAnimation.hpp>
#include <Math/RandomMath.hpp>
#include <Statistical/Distrib.hpp>
#include <Statistical/Matrix.hpp>

using namespace EnjoLib;

AnimationTest::AnimationTest()
{
    TestRotor();
    TestRotor(5);
    TestProgressBar();
    TestProgressBarDistrib();
    TestX();
    TestDistrib();
}

AnimationTest::~AnimationTest(){}

void AnimationTest::TestDistrib() const
{
    const RandomMath rmath;
    const Distrib distr;

    VecD data;
    size_t m_prevStringSize = 0;
    for (int i = 0; i < 700; ++i)
    {
        // break;

        data.push_back(rmath.SampleNormal());

        if (i < 2)
        {
            continue;
        }

        const DistribData & distData = distr.GetDistrib(data, 50);
        const Str & ret2 = distr.PlotLine(distData, true, true);
        m_prevStringSize = AsciiMisc().EraseLineGetPrevSize(ret2, m_prevStringSize);
        ThreadWrap::SleepForMilliseconds(20);
    }

    //cout << "Cov size = " << cov.SizeStr() << endl;
}
void AnimationTest::TestRotor(int skipEvery) const
{
    LOGL << "Test rotor" << Nl;
    static int idx = 0;
    for (int i = 0; i < 200; ++i)
    {
        AsciiAnimation(skipEvery).AnimationPropeller(&idx);
        ThreadWrap::SleepForMilliseconds(20);
    }
}

void AnimationTest::TestProgressBar() const
{
    LOGL << "Test ProgressBar" << Nl;
    ProgressMonitHigh pmh;
    const Str idd = "TestProgressBar";
    const bool onPercentChange = true;
    size_t szz = 200;
    for (size_t i = 0; i < szz; ++i)
    {
        pmh.PrintProgressBarTime(i, szz, idd, onPercentChange);
        ThreadWrap::SleepForMilliseconds(20);
    }
}

void AnimationTest::TestProgressBarDistrib() const
{
    LOGL << "Test ProgressBar with Distrib ID" << Nl;
    const RandomMath rmath;
    const Distrib distr;
    VecD data;
    ProgressMonitHigh pmh;
    const bool onPercentChange = false;
    size_t szz = 400;
    for (size_t i = 0; i < szz; ++i)
    {
        data.push_back(rmath.SampleNormal());

        if (i < 2)
        {
            continue;
        }

        const DistribData & distData = distr.GetDistrib(data, 22);
        const Str & idd = distr.PlotLine(distData, true, true, false);
        pmh.PrintProgressBarTime(i, szz, idd, onPercentChange);
        ThreadWrap::SleepForMilliseconds(20);
    }
}

void AnimationTest::TestX() const
{

}
