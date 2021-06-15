#include "pch_test.h"

#include "DataSets.hpp"

#include <UnitTest++/UnitTest++.h>
#include <Statistical/Matrix.hpp>
#include <Statistical/PCA.hpp>
#include <Statistical/PCAAuto.hpp>
#include <Statistical/EigenAbstract.hpp>

#include <STD/Iostream.hpp>

using namespace std;
using namespace EnjoLib;

TEST(PCA_TestSizes)
{
    const Matrix & iris = DataSets::GetIris();

    const int numFeaturesToLeave = 3;
    const PCA pca(iris, numFeaturesToLeave);

    const Matrix & xtr = pca.Transform(iris);

    CHECK_EQUAL(numFeaturesToLeave, xtr.GetNCols());
    CHECK_EQUAL(iris.GetNRows(), xtr.GetNRows());
}

TEST(PCA_Inverse_close)
{
    const int numFeaturesToLeave = 3;
    const Matrix & iris = DataSets::GetIris();
    const PCA pca(iris, numFeaturesToLeave);
    const Matrix & xtr  = pca.Transform(iris);
    const Matrix & xinv = pca.InverseTransform(xtr);

    //cout << "xtr = " << xtr.at(0).Print() << endl;
    //cout << "iri  sz = " << iris.SizeStr() << endl;
    //cout << "xtr  sz = " << xtr.SizeStr() << endl;
    //cout << "xinv sz = " << xinv.SizeStr() << endl;

    CHECK_ARRAY2D_CLOSE(iris, xinv, iris.GetNRows(), iris.GetNCols(), 0.1);
}

TEST(PCA_Inverse_not_equal)
{
    const int numFeaturesToLeave = 3;
    const Matrix & iris = DataSets::GetIris();
    const PCA pca(iris, numFeaturesToLeave);
    const Matrix & xtr  = pca.Transform(iris);
    const Matrix & xinv = pca.InverseTransform(xtr);

    for (size_t i = 0; i < iris.size(); ++i)
    {
        CHECK(iris.at(i) != xinv.at(i));
    }
}

TEST(PCA_covariance_working_example_PDF_1)
{
    //cout << "PDF 1\n";
    const Matrix & data = DataSets::GetPDF();
    const int numFeaturesToLeave = 1;
    const PCA pca(data, numFeaturesToLeave);
    const Matrix & xtr  = pca.Transform(data);

    CHECK_ARRAY2D_CLOSE(DataSets::GetPDFTransform1(), xtr, data.GetNRows(), numFeaturesToLeave, 0.001);
}

TEST(PCA_covariance_working_example_PDF_2)
{
    //cout << "PDF 2\n";
    const Matrix & data = DataSets::GetPDF();
    const int numFeaturesToLeave = 2;
    const PCA pca(data, numFeaturesToLeave);
    const Matrix & xtr  = pca.Transform(data);

    CHECK_ARRAY2D_CLOSE(DataSets::GetPDFTransform2(), xtr, data.GetNRows(), numFeaturesToLeave, 0.001);
}

TEST(PCA_auto)
{
    const Matrix & data = DataSets::GetIris();
    const PCAAuto pcaAuto;
    {
        const double quality = 0.91;
        const int expected = 1;
        const int minComp1 = pcaAuto.FindMinimalComponents(data, quality);
        const int minComp2 = pcaAuto.FindMinimalComponentsBinSearch(data, quality);
        CHECK_EQUAL(expected, minComp1);
        CHECK_EQUAL(expected, minComp2);
    }
    {
        const double quality = 0.9999;
        const int expected = 4;
        const int minComp1 = pcaAuto.FindMinimalComponents(data, quality);
        const int minComp2 = pcaAuto.FindMinimalComponentsBinSearch(data, quality);
        CHECK_EQUAL(expected, minComp1);
        CHECK_EQUAL(expected, minComp2);
    }
    {
        const double quality = 0.93;
        const int expected = 1;
        const int minComp1 = pcaAuto.FindMinimalComponents(data, quality);
        const int minComp2 = pcaAuto.FindMinimalComponentsBinSearch(data, quality);
        CHECK_EQUAL(expected, minComp1);
        CHECK_EQUAL(expected, minComp2);
        //cout << "minComp = " << minComp << endl;
    }
    {
        const double quality = 0.2;
        const int expected = 1;
        const int minComp1 = pcaAuto.FindMinimalComponents(data, quality);
        const int minComp2 = pcaAuto.FindMinimalComponentsBinSearch(data, quality);
        CHECK_EQUAL(expected, minComp1);
        CHECK_EQUAL(expected, minComp2);
        //cout << "minComp = " << minComp << endl;
    }

}
