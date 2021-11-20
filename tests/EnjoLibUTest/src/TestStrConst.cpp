#include "pch_test.h"

//#include "TestClasses.h"
#include <Util/StrConst.hpp>
#include <Util/Str.hpp>

#include <UnitTest++/UnitTest++.h>

using namespace std;
using namespace EnjoLib;

static const char * inpConst = "asd";

TEST(StrConst_1)
{
    StrConst a(inpConst);
    CHECK_EQUAL(inpConst, a.c_str());
}

TEST(StrConst_nullptr)
{
    StrConst a(nullptr);
    
    CHECK_EQUAL(Str(), Str(a.c_str()));
}