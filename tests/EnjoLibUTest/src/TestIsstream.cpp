#include "pch_test.h"

#include <UnitTest++/UnitTest++.h>
#include <Ios/Isstream.hpp>
#include <Ios/Ofstream.hpp>

//#include <fstream>
//#include <iistream>

using namespace std;
using namespace EnjoLib; 

/*
static void IstrHandler(std::istream & istr, const EnjoLib::Str & strData)
{
    //istr >> strData;
}
*/

TEST(Isstream_1)
{
    const EnjoLib::Str strIn = "bla";
    EnjoLib::Str strOut;
    Isstream istr(strIn);
    istr >> strOut;
    CHECK_EQUAL(strIn, strOut);
}

TEST(Isstream_bool_true)
{
    const EnjoLib::Str strIn = "1";
    bool dir = false;
    Isstream istr(strIn);
    istr >> dir;
    CHECK_EQUAL(true, dir);
}

TEST(Isstream_bool_false)
{
    const EnjoLib::Str strIn = "0";
    bool dir = true;
    Isstream istr(strIn);
    istr >> dir;
    CHECK_EQUAL(false, dir);
}

TEST(Isstream_bool_failed_empty)
{
    const EnjoLib::Str strIn = "1";
    bool dir = false;
    Isstream istr;
    istr >> dir;
    CHECK_EQUAL(false, dir);
}

TEST(Isstream_bool_true_str)
{
    const EnjoLib::Str strIn = "1";
    bool dir = false;
    Isstream istr;
    istr.str(strIn);
    istr >> dir;
    CHECK_EQUAL(true, dir);
}

TEST(Isstream_int_4)
{
    const EnjoLib::Str strIn = "4";
    int val = -1;
    Isstream istr(strIn);
    istr >> val;
    CHECK_EQUAL(4, val);
}

TEST(Isstream_chained_fail)
{
    const EnjoLib::Str strIn = "4";
    int cx, cy = -1;
    Isstream istr(strIn);
    if (!(istr >> cx >> cy))
    {
        CHECK(true);
    }
    else
    {
        CHECK(false);
    }
}

TEST(Isstream_chained_good)
{
    const EnjoLib::Str strIn = "4";
    int cx = -1;
    Isstream istr(strIn);
    if (!(istr >> cx))
    {
        CHECK(false);
    }
    else
    {
        CHECK(true);
    }
}

TEST(Isstream_getline)
{
    const EnjoLib::Str strIn = "EURGBP-GBPCHF-h1 = -0.942323\nEURGBP-GBPCHF-h1 = -0.942323\n";
    Isstream istr(strIn);
    EnjoLib::Str line;
    GetLine(istr, line);
    
    istringstream istrStd(strIn.str());
    std::string lineStd;
    std::getline(istrStd, lineStd);
    
    CHECK_EQUAL(lineStd, line.str());
}
