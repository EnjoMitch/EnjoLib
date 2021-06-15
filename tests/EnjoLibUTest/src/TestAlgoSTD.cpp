#include "pch_test.h"

#include <UnitTest++/UnitTest++.h>

#include <Util/AlgoSTDIVec.hpp>
#include <Util/VecF.hpp>
#include <Util/VecD.hpp>
#include <STD/VectorCpp.hpp>

using namespace EnjoLib;

TEST(Sort_1)
{
    VecF data = std::vector<float>{2, 0, 1};
    AlgoSTDIVec<float>().Sort(&data);
    CHECK_EQUAL(data.at(0), 0);
    CHECK_EQUAL(data.at(1), 1);
    CHECK_EQUAL(data.at(2), 2);
}

static EnjoLib::VecD GatherObservations()
{
    VecD observations;

    observations.push_back(2);
    observations.push_back(1);
    observations.push_back(12);
    observations.push_back(10);
    return observations;
}

static float CalcPoints()
{
    VecD observations = GatherObservations();
    if (observations.Mean() == 0)
    {
        return 0;
    }
    AlgoSTDIVec<double>().Sort(&observations);
    return observations.Mean();
}

TEST(Sort_2_long_wick)
{
    CalcPoints();
}

