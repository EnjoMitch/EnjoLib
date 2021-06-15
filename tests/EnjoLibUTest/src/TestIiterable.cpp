#include "pch_test.h"

#include <UnitTest++/UnitTest++.h>

#include <Util/AlgoSTDIVec.hpp>
#include <Util/VecF.hpp>
#include <Util/VecD.hpp>
#include <Template/Array.hpp>
#include <Template/View.hpp>
#include <Template/VectorViewable.hpp>
#include <Template/IterAdaptStd.hpp>
#include <Util/CoutBuf.hpp>

#include <STD/Algorithm.hpp>
#include <numeric>

using namespace EnjoLib;

template<class T> 
static void RunIterable(const IIterableConst<T> & itr)
{
    for (const auto & val : itr)
    {
        //LOGL << val << NL3;
        (void)val;
    }
}

TEST(IIterable_0)
{
    VecF dat{1 ,2 ,3};
    VectorViewable<float> vecView;
    vecView.dat.push_back(33);
    RunIterable(VecF{1 ,2 ,3});
    RunIterable(VecD{1 ,2 ,3});
    RunIterable(Array<float>(dat));
    RunIterable(View<float>(dat));
    RunIterable(vecView);
}


TEST(IIterable_empty)
{
    VectorViewable<float> vecView, vecViewEmpty;
    vecView.dat.push_back(33);
    CHECK_EQUAL(true, vecViewEmpty.empty());
    CHECK_EQUAL(false, vecView.empty());
}

TEST(IIterable_accumulate)
{
    const float inp = 33;
    VectorViewable<float> vecView, vecViewEmpty;
    vecView.dat.push_back(inp);
    const float res = std::accumulate(vecView.begin(), vecView.end(), 0.0);
    CHECK_EQUAL(res, inp);
}

TEST(IIterable_low_bound)
{
    const float inp = 33;
    VectorViewable<float> vecView, vecViewEmpty;
    vecView.dat.push_back(inp);
    IterAdaptStdConst<float> wrp(&vecView);
    std::lower_bound(wrp.begin(), wrp.end(), inp);
    //CHECK_EQUAL(res, inp);
}
