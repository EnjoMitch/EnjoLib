#include "pch_test.h"

#include <Util/Str.hpp>
#include <Util/ToolsMixed.hpp>
#include <Ios/Sstream.hpp>

#include <UnitTest++/UnitTest++.h>

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
