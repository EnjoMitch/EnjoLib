#include "pch_test.h"

#include <UnitTest++/UnitTest++.h>
#include <Util/CharManipulations.hpp>

#include <STD/Iostream.hpp>

using namespace std;
using namespace EnjoLib;

TEST(CharMan_Trim_simple)
{
    const CharManipulations cman;
    const EnjoLib::Str exp = "str";
    const EnjoLib::Str inp = "  " + exp + "  ";
    const EnjoLib::Str ret = cman.Trim(inp);
    CHECK_EQUAL(exp, ret);
}

TEST(CharMan_Trim_hard)
{
    const CharManipulations cman;
    const EnjoLib::Str exp = "st r";
    const EnjoLib::Str inp = "  " + exp + " ";
    const EnjoLib::Str ret = cman.Trim(inp);
    CHECK_EQUAL(exp, ret);
}

TEST(CharMan_Trim_hard2)
{
    const CharManipulations cman;
    const EnjoLib::Str exp = "st r";
    const EnjoLib::Str inp = "  " + exp + "  ";
    const EnjoLib::Str ret = cman.Trim(inp);
    CHECK_EQUAL(exp, ret);
}

TEST(CharMan_Trim_spaces)
{
    const CharManipulations cman;
    const EnjoLib::Str exp = "";
    const EnjoLib::Str inp = "    ";
    const EnjoLib::Str ret = cman.Trim(inp);
    CHECK_EQUAL(exp, ret);
}
