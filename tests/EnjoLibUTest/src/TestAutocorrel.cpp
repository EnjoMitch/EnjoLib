#include "pch_test.h"

#include <UnitTest++/UnitTest++.h>
#include <Statistical/Autocorrelation.hpp>
//#include <Statistical/VecD.hpp>
#include <Util/VecD.hpp>
#include <STD/Iostream.hpp>

using namespace std;
using namespace EnjoLib;

TEST(Acorrel_test_1)
{
    VecD data;
    for (int i = 0; i < 20; ++i)
        data.Add(i);

    const int per = 10;
    VecD correl(per, 1.0);

    const Autocorrelation acr(data, per);
    const VecD & ret = acr.Calc(data.size()-1);
    //cout << "Acorel = " << ret.Print() << endl;
    CHECK_ARRAY_EQUAL(correl, ret, per);
}

TEST(Acorrel_test_2)
{
    VecD data;
    for (int i = 0; i < 20; ++i)
        data.Add(static_cast <double> (rand()) / static_cast <double> (RAND_MAX));

    const int per = 10;
    VecD correl(per, 1.0);

    const Autocorrelation acr(data, per);
    const VecD & ret = acr.Calc(data.size()-1);
    //cout << "Acorel = " << ret.Print() << endl;
    //CHECK_ARRAY_EQUAL(correl, ret, per);
}
