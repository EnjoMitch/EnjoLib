#include "VectorDTest.h"

//#include <Statistical/VecD.hpp>
#include <Statistical/Matrix.hpp>
#include <Statistical/Statistical.hpp>
#include <Math/GeneralMath.hpp>
#include <Util/Str.hpp>
#include <Util/CoutBuf.hpp>

#include <vector>

using namespace EnjoLib;
VectorDTest::VectorDTest()
{
    ELO
    std::vector<bool> one {1, 1, 0};
    std::vector<bool> two {1, 0, 0};
    std::vector<bool> thr {1, 1, 1};

    Matrix mat;
    mat.push_back(one);
    mat.push_back(two);
    mat.push_back(thr);

    const VecD means = Statistical().MeanCols(mat);

    LOG << "Means = " << means.Print() << Endl;
    std::vector<bool> ret;
    for (const double d : means)
        ret.push_back(GeneralMath().round(d));
    LOG << "Means = " << VecD(ret).Print() << Endl;

}

VectorDTest::~VectorDTest()
{
    //dtor
}
