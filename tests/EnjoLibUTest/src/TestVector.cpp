#include "pch_test.h"

#include <UnitTest++/UnitTest++.h>
#include <Util/VecF.hpp>
#include <Util/VecD.hpp>

using namespace std;
using namespace EnjoLib;

static const VecF tss        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
static const VecF tssHalf1st {1, 2, 3, 4, 5};
static const VecF tssHalf2nd {6, 7, 8, 9, 10};

static const VecF tss3       {6, 7, 8, 9, 10};

TEST(Vector_slice_half)
{
    {
        const VecF & tss1 = tss.Slice(4, 5);

        CHECK_EQUAL(tssHalf1st.size(), tss1.size());
        CHECK_ARRAY_EQUAL(tssHalf1st,  tss1, tss1.size());
    }
    {
        const VecF & tss2 = tss.Slice(9, 5);

        CHECK_EQUAL(tssHalf2nd.size(), tss2.size());
        CHECK_ARRAY_EQUAL(tssHalf2nd,  tss2, tss2.size());
    }
}

TEST(Vector_diff)
{
    //new VecF();
    const VecF & tssDiff = tss.Diffs();
    CHECK_EQUAL(tssDiff.size(), tss.size());
    for (unsigned i = 0; i < tss.size(); ++i)
    {
        if (i == 0)
        {
            CHECK_EQUAL(0, tssDiff.at(i));
        }
        else
        {
            CHECK_EQUAL(1, tssDiff.at(i));
        }
    }
    
    tss3.Diffs();
    tss3.at(0);
    tss3[0];
}

static VecD Create()
{
    VecD ret;
    ret.Add(1);
    return ret;
}

TEST(Vector_copy)
{
    VecD observations = Create();
    observations.size();
}


