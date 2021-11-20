#include "pch_test.h"

#include <Util/ToolsMixed.hpp>
#include <UnitTest++/UnitTest++.h>

using namespace EnjoLib;

TEST(Gen_lines_1)
{
    double inp = 30.1;
    Str exp = "[===       ]";

    const Str & ret = ToolsMixed().GenBars10(inp);
    CHECK_EQUAL(exp, ret);
}

TEST(Gen_lines_95)
{
    double inp = 95.1;
    Str exp = "[==========]";

    const Str & ret = ToolsMixed().GenBars10(inp);
    CHECK_EQUAL(exp, ret);
}

TEST(Gen_lines_111)
{
    double inp = 111;
    Str exp = "[==========]";

    const Str & ret = ToolsMixed().GenBars10(inp);
    CHECK_EQUAL(exp, ret);
}