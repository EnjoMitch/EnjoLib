#include "pch_test.h"

#include "DataSets.hpp"

#include <UnitTest++/UnitTest++.h>
#include <Statistical/Matrix.hpp>
#include <Statistical/Statistical.hpp>
#include <Statistical/EigenAbstract.hpp>
#include <Template/CorradePointer.h>
#include <STD/VectorCpp.hpp>

#include <STD/Iostream.hpp>

using namespace std;
using namespace EnjoLib;

TEST(Statistical_covariance_size_smaller)
{
    const Statistical stat;

    Matrix data;
    data.push_back({1, 2});
    data.push_back({1, 2});
    data.push_back({1, 2});
    data.push_back({1, 2});

    const Matrix & cov = stat.CovarianceMatrix(data);

    CHECK_EQUAL(cov.GetNCols(), cov.GetNRows());
    CHECK_EQUAL(data.GetNCols(), cov.GetNCols());
    CHECK_EQUAL(data.GetNCols(), cov.GetNRows());

    //cout << "Cov size = " << cov.SizeStr() << endl;
}

TEST(Statistical_covariance_working_example)
{
    const Statistical stat;

    Matrix data;
    data.push_back({4.0, 2.0, 0.60});
    data.push_back({4.2, 2.1, 0.59});
    data.push_back({3.9, 2.0, 0.58});
    data.push_back({4.3, 2.1, 0.62});
    data.push_back({4.1, 2.2, 0.63});

    Matrix covExp;
    covExp.push_back({0.025,   0.0075,   0.00175});
    covExp.push_back({0.0075,  0.0070,   0.00135});
    covExp.push_back({0.00175, 0.00135,  0.00043});

    const Matrix & cov = stat.CovarianceMatrix(data);

    CHECK_ARRAY2D_CLOSE(covExp, cov, covExp.GetNRows(), covExp.GetNCols(), 0.0001);
}

TEST(Statistical_covariance_working_example_PDF)
{
    const Statistical stat;

    const Matrix & data = DataSets::GetPDF();

    Matrix covExp;
    covExp.push_back({0.6166, 0.6154});
    covExp.push_back({0.6154, 0.7166});

    const Matrix & cov = stat.CovarianceMatrix(data);

    const double EPS = 0.001;
    CHECK_ARRAY2D_CLOSE(covExp, cov, covExp.GetNRows(), covExp.GetNCols(), EPS);

    const Corrade::Containers::Pointer<EigenAbstract> peigen = EigenAbstract::CreateDefault();
    const std::vector<EigenValueVector> evalvec = peigen->GetEigenValVec(cov, true);

    CHECK_CLOSE(1.28402771, evalvec.at(0).GetValue(), EPS);
    CHECK_CLOSE(0.04908339, evalvec.at(1).GetValue(), EPS);

    VecD vec0 = {-0.67787, -0.735179};
    VecD vec1 = {-0.73518, +0.67787};

    // Transposed nonsense:
    //VectorD vec0 = {+0.67787, -0.735179};
    //VectorD vec1 = {-0.73518, -0.67787, };
    CHECK_ARRAY_CLOSE(vec0, evalvec.at(0).GetVector(), covExp.GetNCols(), EPS);
    CHECK_ARRAY_CLOSE(vec1, evalvec.at(1).GetVector(), covExp.GetNCols(), EPS);
}


TEST(Statistical_Median)
{
    const Statistical stat;
    // TODO

    //cout << "Cov size = " << cov.SizeStr() << endl;
}