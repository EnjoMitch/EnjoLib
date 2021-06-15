#include <Template/VectorViewable.hpp>
#include <Template/IterAdaptStd.hpp>
#include <Util/Iters.hpp>

#include <iterator>
#include <algorithm>
#include <numeric>

using namespace EnjoLib;

static void FunVectorViewable(const IIterableConst<float> & itr)
{
    for (const auto & val : itr){}
    std::accumulate(itr.begin(), itr.end(), 0.0);
    IterAdaptStdConst<float> wrp(&itr);
    std::distance(wrp.begin(), wrp.end());
    const float inp = 3;
    std::lower_bound(wrp.begin(), wrp.end(), inp);
}

static void FunVectorModify(IIterable<float> & itr)
{
    for (const auto & val : itr){}
    std::accumulate(itr.begin(), itr.end(), 0.0);
    IterAdaptStd<float> wrp(&itr);
    std::sort(wrp.begin(), wrp.end());
}

static void FunVectorViewableRun(int i)
{
    if (i == 0)
    {
        return;
    }
    VectorViewable<float> vec;
    FunVectorViewable(vec);
    FunVectorModify(vec);
    FunVectorViewableRun(0);
}
