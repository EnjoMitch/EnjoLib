#include "pch_test.h"

#include <Math/Opti/SelectBestFromBest.hpp>
#include <Statistical/Matrix.hpp>

#include <UnitTest++/UnitTest++.h>
#include <STD/Iostream.hpp>

using namespace std;
using namespace EnjoLib;

static Matrix GetMat()
{
    Matrix ret;

    return ret;
}

TEST(SelectBestFromBest_1)
{
    const Matrix & mat = GetMat();
    CHECK(true);
}
