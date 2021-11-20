#include "pch_test.h"

#include <UnitTest++/UnitTest++.h>
#include <Util/ToolsMixed.hpp>
#include <Ios/Sstream.hpp>

using namespace std;
using namespace EnjoLib;

TEST(Sstream_1)
{
    const Str exp = "text";
    Str ret;
    Sstream sstr;
    
    sstr << exp;
    sstr >> ret;

    CHECK_EQUAL(exp, ret);
}
