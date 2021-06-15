#include "pch_test.h"

#include <UnitTest++/UnitTest++.h>
#include <Statistical/Matrix.hpp>

#include <STD/Iostream.hpp>
#include <STD/VectorCpp.hpp>
#include <Util/VecD.hpp>

using namespace std;
using namespace EnjoLib;

TEST(Matrix_2Transposes_equal)
{
    Matrix mat;
    mat.push_back({1, 2, 3});
    mat.push_back({4, 5, 6});
    const Matrix matStart = mat;

    CHECK(mat.T().GetNCols() != matStart.GetNCols());
    CHECK(mat.T().GetNRows() != matStart.GetNRows());

    CHECK_EQUAL(mat.T().GetNCols(), matStart.GetNRows());
    CHECK_EQUAL(mat.T().GetNRows(), matStart.GetNCols());

    CHECK_EQUAL(mat.T().T().GetNCols(), matStart.GetNCols());
    CHECK_EQUAL(mat.T().T().GetNRows(), matStart.GetNRows());
}

TEST(Matrix_AdjustMeanCols)
{
    Matrix mat;
    mat.push_back({1, -1, 3});
    mat.push_back({1, +1, 5});
    const Matrix adjCol = mat.AdjustMeanCols();
    const Matrix adjColT = adjCol.T();
    CHECK_EQUAL(+0, adjColT.at(0).at(0));
    CHECK_EQUAL(-1, adjColT.at(1).at(0));
    CHECK_EQUAL(-1, adjColT.at(2).at(0));
}

TEST(Matrix_mul)
{
    Matrix matFeatVec;
    matFeatVec.push_back({1, 2});
    matFeatVec.push_back({1, 2});
    matFeatVec.push_back({1, 2});

    Matrix matData;
    matData.push_back({1, 2, 3});
    matData.push_back({1, 2, 3});
    matData.push_back({1, 2, 3});
    matData.push_back({1, 2, 3});
    matData.push_back({1, 2, 3});
    matData.push_back({1, 2, 3});
    matData.push_back({1, 2, 3});


    const Matrix & matMul = matFeatVec.T() * matData.T();
    const Matrix & matMulT = matMul.T();
    //cout << "MatMul size = " << matMul.T().SizeStr() << "\n";
    CHECK_EQUAL(matData.GetNRows(),    matMulT.GetNRows());
    CHECK_EQUAL(matData.GetNCols()-1,  matMulT.GetNCols()); // Reduced by one feature
    CHECK_EQUAL(matFeatVec.GetNCols(), matMulT.GetNCols()); // Reduced by one feature
}

TEST(Matrix_getCol)
{
    Matrix matFeatVec;
    matFeatVec.push_back({1, 1});
    matFeatVec.push_back({1, 2});
    matFeatVec.push_back({1, 3});

    const VecD & colGot = matFeatVec.GetCol(1);
    const VecD   colExp = {1, 2, 3};

    CHECK_ARRAY_EQUAL(colExp, colGot, colExp.size());
}

TEST(Matrix_FilterByMask)
{
    Matrix matFeatVec;
    matFeatVec.push_back({1, 2, 3, 4});
    matFeatVec.push_back({1, 2, 3, 4});

    const std::vector<bool> mask {1, 0, 1, 0};

    const Matrix & matMasked = matFeatVec.FilterByMask(mask);
    const VecD colExp = {1, 3};
    const VecD colGot = matMasked.at(0);

    CHECK_EQUAL(matFeatVec.size(), matMasked.size());
    CHECK_EQUAL(colExp.size(), colGot.size());
    CHECK_ARRAY_EQUAL(colExp, colGot, colExp.size());
}

TEST(Matrix_Flatten)
{
    Matrix matFeatVec;
    matFeatVec.push_back({1, 2, 3});
    matFeatVec.push_back({4, 5, 6});

    const VecD & matFlat = matFeatVec.Flatten();
    const VecD colExp = {1, 2, 3, 4, 5, 6};

    CHECK_EQUAL(colExp.size(), matFlat.size());
    CHECK_ARRAY_EQUAL(colExp, matFlat, colExp.size());
}

TEST(Matrix_Apply_Weights)
{
    Matrix matFeatVec;
    matFeatVec.push_back({2, 4, 6});
    matFeatVec.push_back({8, 10, 12});

    const VecD weights {1, 0, 0.5};

    const Matrix & matWeighted = matFeatVec.FilterByMaskD(weights);
    CHECK_EQUAL(matFeatVec.size(), matWeighted.size());

    const VecD colExp1 = {2, 0, 3};
    const VecD colExp2 = {8, 0, 6};
    const VecD colGot1 = matWeighted.at(0);
    const VecD colGot2 = matWeighted.at(1);

    CHECK_EQUAL(colExp1.size(), colGot1.size());
    CHECK_EQUAL(colExp2.size(), colGot2.size());
    CHECK_ARRAY_EQUAL(colExp1, colGot1, colExp1.size());
    CHECK_ARRAY_EQUAL(colExp2, colGot2, colExp2.size());
}
