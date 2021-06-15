#include "pch_test.h"

#include <UnitTest++/UnitTest++.h>
#include <Math/GeneralMath.hpp>

#include <STD/Iostream.hpp>
#include <cmath>

using namespace std;
using namespace EnjoLib;

static const GeneralMath gmat;

TEST(Concatenate_1)
{
    int in1 = 10;
    int in2 = 56;

    int res1 = gmat.Concatenate(in1, in2);
    int res2 = gmat.Concatenate(in2, in1);
    CHECK_EQUAL(1056, res1);
    CHECK_EQUAL(5610, res2);
}

TEST(Concatenate_2)
{
    int in1 = 1;
    int in2 = 56;

    int res1 = gmat.Concatenate(in1, in2);
    int res2 = gmat.Concatenate(in2, in1);

    CHECK_EQUAL(156, res1);
    CHECK_EQUAL(561, res2);
}

TEST(Concatenate_leading0_2)
{
    int in1 = 1;
    int in2 = 56;

    int leading0 = 1;

    int res1 = gmat.Concatenate(in1, in2, leading0);
    int res2 = gmat.Concatenate(in2, in1, leading0);

    CHECK_EQUAL(156, res1);
    CHECK_EQUAL(5601, res2);
}

TEST(Concatenate_date)
{
    int leading0 = 1;

    long long int date = 0;
    date = gmat.Concatenate(date, 2015);
    date = gmat.Concatenate(date, 1, leading0);
    date = gmat.Concatenate(date, 6, leading0);
    date = gmat.Concatenate(date, 2, leading0);
    date = gmat.Concatenate(date, 0, leading0);
    date = gmat.Concatenate(date, 0, leading0);


    CHECK_EQUAL(20150106020000, date);
}

TEST(Concatenate_PowInt)
{
    CHECK_EQUAL(pow(3, 2), gmat.PowInt(3, 2));
    CHECK_EQUAL(pow(2.5, 2), gmat.PowInt(2.5, 2));
    CHECK_EQUAL(pow(2.5, 5), gmat.PowInt(2.5, 5));
}

