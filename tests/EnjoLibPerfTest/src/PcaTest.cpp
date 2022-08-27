#include "PcaTest.h"

//#include <Util/ProgressMonitHigh.hpp>
#include <Ios/Osstream.hpp>
#include <Ios/Ofstream.hpp>
#include <Util/CoutBuf.hpp>
#include <Util/Str.hpp>
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
    TestMatrixTransp();
    TestMatrixMul();
    TestDistrib();
    //return;
    TestPca1();
    TestPcaAuto();
    
    
    Log("Total", timer, 0);
}

PcaTest::~PcaTest(){}

void PcaTest::Log(const EnjoLib::Str & descr, const EnjoLib::Timer & timer, const int iter) const
{
#ifdef EL_FLOATING_POINT_LOW_PRECISION
    const Str fpName = "float";
#else
    const Str fpName = "double";
#endif // EL_FLOATING_POINT_LOW_PRECISION
    Osstream oss;
    oss << descr <<"\t (" << iter << " iters)\t" << " finished in: " << timer.GetElapsedSeconds() << " s\n";
    const Str fname = "perf-test-" + fpName + ".log";
    Ofstream ofs(fname, true, true);
    ofs << oss.str();
    LOGL << oss.str();
    //{LOGL << "Saved log to " << fname << Nl;}
}

void PcaTest::TestDistrib() const
{
    const int ITER = 3e3;
    const RandomMath rmath;
    const Distrib distr;

    VecD data;
    const Timer timer;
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
    
    Log("Distrib\t", timer, ITER);
}

void PcaTest::TestPca1() const
{
    const int ITER = 1e4;
    const int numFeaturesToLeave = 3;
    const Matrix & iris = DataSets::GetIris();
    const auto eig = EigenFactory().Create(EIGENTYPE_DEFAULT);
    const Timer timer;
    for (int i = 0; i < ITER; ++i)
    {    
        const PCA pca(*eig, iris, numFeaturesToLeave);
        const Matrix & xtr  = pca.Transform(iris);
        const Matrix & xinv = pca.InverseTransform(xtr);
    }
    Log("PCA_1\t", timer, ITER);
}

void PcaTest::TestPcaAuto() const
{
    const int ITER = 4e3;
    const Matrix & data = DataSets::GetIris();
    const auto eig = EigenFactory().Create(EIGENTYPE_DEFAULT);
    const PCAAuto pcaAuto;
    const Timer timer;
    
    for (int i = 0; i < ITER; ++i)
    {
        // break;

        const double quality = 0.93;
        const int minComp1 = pcaAuto.FindMinimalComponents(*eig, data, quality);
        const int minComp2 = pcaAuto.FindMinimalComponentsBinSearch(*eig, data, quality);
    }
    Log("PCA_auto", timer, ITER);
}

void PcaTest::TestMatrixMul() const
{
    Matrix matData;
    matData.push_back({1, 2, 3});
    matData.push_back({1, 2, 3});
    matData.push_back({1, 2, 3});
    matData.push_back({1, 2, 3});
    matData.push_back({1, 2, 3});
    matData.push_back({1, 2, 3});
    matData.push_back({1, 2, 3});

    const Matrix & matDataT = matData.T();
    const Timer timer;
    const int ITER = 2e5;
    for (int i = 0; i < ITER; ++i)
    {
        const Matrix & matMul = matDataT * matData;
    }
    Log("Matrix mul", timer, ITER);    
}

void PcaTest::TestMatrixTransp() const
{
    Matrix matData;
    matData.push_back({1, 2, 3});
    matData.push_back({1, 2, 3});
    matData.push_back({1, 2, 3});
    matData.push_back({1, 2, 3});
    matData.push_back({1, 2, 3});
    matData.push_back({1, 2, 3});
    matData.push_back({1, 2, 3});

    const Timer timer;
    const int ITER = 4e5;
    for (int i = 0; i < ITER; ++i)
    {
        const Matrix & matT = matData.T();
    }
    Log("Matrix Trans", timer, ITER);
}