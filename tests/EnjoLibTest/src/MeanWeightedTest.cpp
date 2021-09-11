#include "MeanWeightedTest.h"
#include <Statistical/MeanWeighted.hpp>
#include <Util/CoutBuf.hpp>

using namespace std;
using namespace EnjoLib;

MeanWeightedTest::MeanWeightedTest()
{
    EnjoLib::MeanWeighted wmn;
    wmn.AddValWeight(1, 3);
    wmn.AddValWeight(3, 1);

    LOGL << "Mean = " << wmn.GetMean() << Endl;
}

MeanWeightedTest::~MeanWeightedTest()
{
    //dtor
}
