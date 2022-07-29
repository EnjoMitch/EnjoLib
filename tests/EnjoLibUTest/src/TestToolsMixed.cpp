#include "pch_test.h"

#include <Util/ToolsMixed.hpp>
#include <Util/CoutBuf.hpp>
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


TEST(MixUtils_values_to_ascii1)
{
    const double minimum = 0;
    const double maximum = 10;
    VecD inp;
    for (int i = 1; i >= -2; --i)
    {
        inp.Add(i);
    }
    for (int i = 0; i <= 12; ++i)
    {
        inp.Add(i);
    }
    ToolsMixed().GetPercentToAscii(inp, minimum, maximum);
    LOGL << "values_to_ascii1:" << Nl << ToolsMixed().GetPercentToAscii(inp, minimum, maximum) << Nl;
}
