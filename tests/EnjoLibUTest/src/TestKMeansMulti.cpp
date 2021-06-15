#include "pch_test.h"

#include <UnitTest++/UnitTest++.h>
#include <Statistical/VectorD.hpp>
#include <Statistical/MeanWeighted.hpp>

#include <STD/Iostream.hpp>

using namespace std;
using namespace EnjoLib;

TEST(kmeans_multi_2)
{
    MeanWeighted mvd;
    mvd.AddValWeight(1, 1);
    mvd.AddValWeight(3, 1);

    CHECK_EQUAL(2, mvd.GetMean());
}

static

TEST(kmeans_multi_dist_1)
{
    MeanWeighted mvd;

    mvd.AddValDist(1, 1);
    mvd.AddValDist(3, 1);

    CHECK_EQUAL(2, mvd.GetMean());
}

TEST(kmeans_multi_dist_2)
{
    MeanWeighted mvd;

    mvd.AddValDist(1,  1);
    mvd.AddValDist(10, 10);
    mvd.AddValDist(10, 10);

    CHECK_CLOSE(2.5, mvd.GetMean(), 0.01);
}
