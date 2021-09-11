#include "pch_test.h"

#include <UnitTest++/UnitTest++.h>

using namespace std;
//using namespace EnjoLib;

TEST(New_templ)
{
    const bool exp = true;
    const bool ret = true;
    CHECK_EQUAL(exp, ret);
}
