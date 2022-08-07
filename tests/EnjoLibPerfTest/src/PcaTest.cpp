#include "PcaTest.h"

//#include <Util/ProgressMonitHigh.hpp>
#include <Util/CoutBuf.hpp>
#include <Util/VecD.hpp>
#include <Util/Timer.hpp>
#include <Math/RandomMath.hpp>
#include <Statistical/Distrib.hpp>
#include <Statistical/Matrix.hpp>
#include <ML/DataSets.hpp>
#include <Statistical/PCA.hpp>
#include <Statistical/PCAAuto.hpp>
#include <Statistical/EigenAbstract.hpp>
#include <Statistical/EigenFactory.hpp>


using namespace EnjoLib;

PcaTest::PcaTest()
{
    const Timer timer;
    LOGL << "Running performance tests" << Nl;
    TestDistrib();
    TestPca1();
    Log("Total", timer, 0);
}

PcaTest::~PcaTest(){}

void PcaTest::Log(const EnjoLib::Str & descr, const EnjoLib::Timer & timer, const int iter) const
{
    LOGL << descr <<"\t (" << iter << " iters)\t" << " finished in: " << timer.GetElapsedSeconds() << " s\n";
}

void PcaTest::TestDistrib() const
{
    const int ITER = 4e3;
    const Timer timer;
    const RandomMath rmath;
    const Distrib distr;

    VecD data;
    for (int i = 0; i < ITER; ++i)
    {
        // break;

        data.push_back(rmath.SampleNormal());

        if (i < 2)
        {
            continue;
        }

        const DistribData & distData = distr.GetDistrib(data, 50);
    }
    
    Log("Distrib", timer, ITER);
}

void PcaTest::TestPca1() const
{
    const int ITER = 6e3;
    const Timer timer;
    const Matrix & data = DataSets::GetIris();
    const auto eig = EigenFactory().Create(EIGENTYPE_DEFAULT);
    const PCAAuto pcaAuto;
    
    for (int i = 0; i < ITER; ++i)
    {
        // break;

        const double quality = 0.93;
        const int minComp1 = pcaAuto.FindMinimalComponents(*eig, data, quality);
        const int minComp2 = pcaAuto.FindMinimalComponentsBinSearch(*eig, data, quality);
    }
    Log("PCA1", timer, ITER);
}
