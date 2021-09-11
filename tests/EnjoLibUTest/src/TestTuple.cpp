#include "pch_test.h"

#include <Util/Tuple.hpp>
#include <UnitTest++/UnitTest++.h>

using namespace EnjoLib;

TEST(Tuple_basic)
{
    Tuple<int, bool> tup;
    
    const int first = 5;
    const bool second = true;
    
    Get<0>(tup) = first;
    Get<1>(tup) = second;
    //Get<2>(tup) = "Foo"; // Error

    CHECK_EQUAL(first,  Get<0>(tup));
    CHECK_EQUAL(second, Get<1>(tup));
    
    const Tuple<int, bool> & tupRef = tup;
    
    CHECK_EQUAL(first,  Get<0>(tupRef));
    CHECK_EQUAL(second, Get<1>(tupRef));
}

TEST(Tuple_make)
{
    /*
    const int first = 5;
    const bool second = true;
    
    const Tuple<int, bool> tup = MakeTuple(first, second);

    CHECK_EQUAL(first,  Get<0>(tup));
    CHECK_EQUAL(second, Get<1>(tup));
    */
}
