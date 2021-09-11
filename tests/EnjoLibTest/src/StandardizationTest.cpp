#include "StandardizationTest.h"
#include <Statistical/Statistical.hpp>
//#include <Statistical/VecD.hpp>
#include <Statistical/Matrix.hpp>
#include <Util/Str.hpp>
#include <Util/CoutBuf.hpp>

#include <STD/VectorCpp.hpp>


using namespace EnjoLib;
using namespace std;

StandardizationTest::StandardizationTest()
{
    TestVec();
    TestMat();
    //TestMatStdDev(); /// TODO: segfaults
}


void StandardizationTest::TestVec() const
{
    ELO
    Statistical stat;
    const VecD vec = GetVec();
    {
        const VecD standardized = stat.Standardize(vec);
        LOG << standardized.PrintPython("Std");
        LOG << "std = " << stat.StandardDeviation(standardized) << Endl;
    }
    {
        VecD apply;
        apply.push_back(vec.at(0));
        apply.push_back(vec.at(1));
        const VecD standardized = stat.Standardize(vec, apply);
        LOG << standardized.PrintPython("Std") << "above should be equal\n";
        LOG << "std = " << stat.StandardDeviation(standardized) << Endl;
    }
}

void StandardizationTest::TestMat() const
{
    ELO
    Statistical stat;
    const Matrix mat = GetMat();
    {
        const Matrix standardized = stat.Standardize(mat);
        LOG << standardized.PrintScilab("Std");
        LOG << "std = " << stat.StandardDeviation(standardized.T().at(0)) << Endl;
        LOG << "std = " << stat.StandardDeviation(standardized.T().at(1)) << Endl;
    }
    {
        //VecD apply;
        //apply.push_back(vec.at(0));
        //apply.push_back(vec.at(1));
        //const VecD standardized = stat.Standardize(vec, apply);
        //LOG << standardized.PrintPython("Std") << "above should be equal\n";
        //LOG << "std = " << stat.StandardDeviation(standardized) << Endl;
    }
}

void StandardizationTest::TestMatStdDev() const
{
    ELO
    LOG << '\n' << "TestMatStdDev()\n";
    const Statistical stat;
    {
        const Matrix mat = GetMat();
        const Matrix standardized = stat.Standardize(mat);
        LOG << standardized.PrintScilab("Std");
        LOG << "Mean = " << standardized.T().at(1).Mean() << Endl;
        LOG << "StdDev 2d = " << stat.StandardDeviation(standardized) << Endl;
        LOG << "std = " << stat.StandardDeviation(standardized.T().at(0)) << Endl;
        //LOG << "std = " << stat.StandardDeviation(standardized.T().at(1)) << Endl;

        EnjoLib::VecD vecd(vector<double>{20, -20});
        LOG << "DistToMean = " << stat.DistFromMean(standardized, stat.Standardize(vecd)) << Endl;
        //stat.Centroid(
    }
}

VecD StandardizationTest::GetVec() const
{
    VecD vec;
    vec.push_back(100);
    vec.push_back(150);
    vec.push_back(200);
    vec.push_back(250);
    vec.push_back(300);
    vec.push_back(350);
    vec.push_back(400);
    return vec;
}

Matrix StandardizationTest::GetMat() const
{
    Matrix mat;
    mat.push_back(EnjoLib::VecD {10, -10}); // Each row is observation
    mat.push_back(EnjoLib::VecD {20, -20});
    mat.push_back(EnjoLib::VecD {30, -30});
    mat.push_back(EnjoLib::VecD {40, -40});
    mat.push_back(EnjoLib::VecD {50, -50});
    mat.push_back(EnjoLib::VecD {60, -60});
    mat.push_back(EnjoLib::VecD {70, -70});
    return mat;
}
