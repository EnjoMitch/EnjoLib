#include "pch_test.h"

#include <Statistical/MovingWindow.hpp>
#include <UnitTest++/UnitTest++.h>

#include <STD/Iostream.hpp>

using namespace std;
using namespace EnjoLib;

static const VecD tss        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
static const VecD tssHalf1st {1, 2, 3, 4, 5};
static const VecD tssHalf2nd {6, 7, 8, 9, 10};

TEST(MovingWindow_slice_half)
{
    const MovingWindow mov(5, tss);
    CHECK(mov.IsValid());

    const Matrix & sets = mov.GetSets();
    CHECK(not sets.empty());
    CHECK_EQUAL(sets.size(), mov.GetNumSets());

    CHECK_ARRAY_EQUAL(tssHalf1st,  sets.First(), tssHalf1st.size());
    CHECK_ARRAY_EQUAL(tssHalf2nd,  sets.Last(),  tssHalf2nd.size());
    //for (const auto & vset : sets)
    {
        //cout << vset.Print() << endl;
    }
}

TEST(MovingWindow_edge)
{
    const MovingWindow mov(tss.size(), tss);
    CHECK(mov.IsValid());

    const Matrix & sets = mov.GetSets();
    CHECK(not sets.empty());
    CHECK_EQUAL(sets.size(), mov.GetNumSets());

    CHECK_ARRAY_EQUAL(tss,  sets.First(), tss.size());
}

TEST(MovingWindow_too_large)
{
    const MovingWindow mov(tss.size() + 1, tss);
    CHECK(not mov.IsValid());

    const Matrix & sets = mov.GetSets();
    CHECK(sets.empty());
    CHECK_EQUAL(sets.size(), mov.GetNumSets());
}
