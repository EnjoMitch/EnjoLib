#include "pch_test.h"

#include "TestClasses.h"
#include <Util/Str.hpp>

#include <UnitTest++/UnitTest++.h>

#include <STD/Iostream.hpp>

using namespace std;
using namespace EnjoLib;

static const char * inp = "asd";

TEST(Str_1)
{
    Str a(inp);
    CHECK_EQUAL(inp, a.str());
}

TEST(Str_epmty)
{
    Str a;
    CHECK_EQUAL("", a.str());
}

TEST(Str_copying)
{
    Str a(inp);
    Str b = a;
    CHECK_EQUAL(b.str(), a.str());
}

TEST(Str_assigning)
{
    Str a(inp);
    Str b("");

    b = a;
    CHECK_EQUAL(b.str(), a.str());
}

TEST(Str_stream)
{
    std::ostringstream oss;
    Str a(inp);
    oss << a;
    CHECK_EQUAL(oss.str(), a.str());
}

TEST(Str_opPlus)
{
    Str a;
    const EnjoLib::Str exp(inp);
    const EnjoLib::Str b = inp + a;
    const EnjoLib::Str c = a + inp;
    CHECK_EQUAL(b, exp);
    CHECK_EQUAL(c, exp);
}

TEST(Str_opPlusRef)
{
    Str a(inp);
    Str b(a + inp);
    const EnjoLib::Str & res1 = b.str();
    const EnjoLib::Str exp = EnjoLib::Str(inp) + inp;

    CHECK_EQUAL(res1, exp);
    //CHECK_EQUAL(res2, exp);
}


TEST(Str_move)
{
    Sym a(Str("asd"));
    Str b(a.GetName());
    const EnjoLib::Str & res1 = b.str();
    const EnjoLib::Str exp = EnjoLib::Str(inp);

    CHECK_EQUAL(res1, exp);
    //CHECK_EQUAL(res2, exp);
}
