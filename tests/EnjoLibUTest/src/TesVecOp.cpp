#include "pch_test.h"

#include <UnitTest++/UnitTest++.h>

#include <Util/VecOp.hpp>
#include <STD/Iostream.hpp>

using namespace std;
using namespace EnjoLib;

TEST(Vector_split_1)
{
    const int num = 3;
    vector<int> inp;
    for (int i = 0; i < 10; ++i)
    {
        inp.push_back(i);
    }

    const vector<vector<int>> & ret = VecOp().Split(inp, num);


    int sum = 0;
    for (unsigned i = 0; i < ret.size(); ++i)
    {
        //cout << "\ni = " << i << endl;
        for (unsigned j = 0; j < ret.at(i).size(); ++j)
        {
            ++sum;
            //cout << ret.at(i).at(j) << ", ";
        }
    }
    //cout << endl;
    CHECK_EQUAL(0, ret.at(0).at(0));
    CHECK_EQUAL(1, ret.at(0).at(1));
    CHECK_EQUAL(2, ret.at(0).at(2));
    CHECK_EQUAL(3, ret.at(1).at(0));
    CHECK_EQUAL(4, ret.at(1).at(1));
    CHECK_EQUAL(5, ret.at(1).at(2));
    CHECK_EQUAL(6, ret.at(2).at(0));

    CHECK_EQUAL(inp.size(), sum);
}
