#include "pch_test.h"

#include <UnitTest++/UnitTest++.h>
#include <Util/StackTrace.hpp>
#include <Util/CharManipulations.hpp>
#include <Util/Str.hpp>

//#include <STD/Iostream.hpp>

using namespace std;
using namespace EnjoLib;

TEST(Strace_1)
{
// Expected:
//virtual void TestStrace_1::RunImpl() const:14
// : msg
    const CharManipulations cman;
    const char * msg = "msg";
    const Str gen = STRACE_THROW(msg);
    //cout << gen << endl;
    CHECK(cman.Contains(gen, msg));
    CHECK(cman.Contains(gen, "Strace_1"));
    CHECK(cman.Contains(gen, ":20"));
        //cout << "Cov size = " << cov.SizeStr() << endl;
}