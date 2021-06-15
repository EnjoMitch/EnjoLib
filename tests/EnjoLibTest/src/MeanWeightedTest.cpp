#include "MeanWeightedTest.h"
#include <Statistical/MeanWeighted.hpp>

#include <STD/Iostream.hpp>

using namespace std;

MeanWeightedTest::MeanWeightedTest()
{
    EnjoLib::MeanWeighted wmn;
    wmn.AddValWeight(1, 3);
    wmn.AddValWeight(3, 1);

    cout << "Mean = " << wmn.GetMean() << endl;
}

MeanWeightedTest::~MeanWeightedTest()
{
    //dtor
}
