#include "pch_test.h"

#include <UnitTest++/UnitTest++.h>
#include <Util/Ifstream.hpp>
#include <Util/Ofstream.hpp>

//#include <fstream>
//#include <iistream>

using namespace std;
using namespace EnjoLib;

static const char * outFileIfstream = "/tmp/Ifstreamfile.txt";
static const EnjoLib::Str strIn = "bla";

/*
static void IstrHandler(std::istream & istr, const EnjoLib::Str & strData)
{
    //istr >> strData;
}
*/

static void PrepOstream(const EnjoLib::Str & strData = strIn)
{
    Ofstream ofs(outFileIfstream);
    ofs << strData;
}

TEST(Ifstream_1)
{
    PrepOstream();
    EnjoLib::Str strOut;
    Ifstream istr(outFileIfstream);
    istr >> strOut;
    CHECK_EQUAL(strIn, strOut);
}

TEST(Ifstream_bool_true)
{
    PrepOstream("1");
    bool dir = false;
    Ifstream istr(outFileIfstream);
    istr >> dir;
    CHECK_EQUAL(true, dir);
}

TEST(Ifstream_bool_false)
{
    PrepOstream("0");
    bool dir = true;
    Ifstream istr(outFileIfstream);
    istr >> dir;
    CHECK_EQUAL(false, dir);
}


TEST(Ifstream_int_4)
{
    PrepOstream("4");
    int val = -1;
    Ifstream istr(outFileIfstream);
    istr >> val;
    CHECK_EQUAL(4, val);
}

TEST(Ifstream_chained_fail)
{
    PrepOstream("4");
    int cx, cy = -1;
    Ifstream istr(outFileIfstream);
    if (!(istr >> cx >> cy))
    {
        CHECK(true);
    }
    else
    {
        CHECK(false);
    }
}

TEST(Ifstream_chained_good)
{
    PrepOstream("4");
    int cx = -1;
    Ifstream istr(outFileIfstream);
    if (!(istr >> cx))
    {
        CHECK(false);
    }
    else
    {
        CHECK(true);
    }
}

