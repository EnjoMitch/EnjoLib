#include "pch_test.h"

#include <UnitTest++/UnitTest++.h>
#include <Util/ToolsMixed.hpp>
#include <Util/Ofstream.hpp>

#include <fstream>
//#include <STD/Iostream.hpp>

using namespace std;
using namespace EnjoLib;

static const EnjoLib::Str outFileOfstream = ToolsMixed::GetTmpDir() + "/ofstreamfile.txt";
static const EnjoLib::Str strIn = "bla";

static void OstrHandler(std::ostream & ostr, const EnjoLib::Str & strData)
{
    ostr << strData;
}

TEST(Ofstream_1)
{
    Ofstream ostr(outFileOfstream);
    ostr << strIn;
    const EnjoLib::Str strOut = ostr.Str();
    CHECK_EQUAL(strIn, strOut);
}

TEST(Ofstream_2file)
{
    {
        Ofstream ostr(outFileOfstream);
        ostr << strIn;
    }
    {
        ifstream ifs(outFileOfstream.c_str());
        string strOut;
        getline(ifs, strOut);
        CHECK_EQUAL(strIn, strOut);
    }
}

TEST(Ofstream_OStr)
{
    Ofstream ostr(outFileOfstream);
    OstrHandler(ostr.OStr(), strIn);
    const EnjoLib::Str strOut = ostr.Str();
    CHECK_EQUAL(strIn, strOut);
}

TEST(Ofstream_number_int)
{
    int a = 1;
    Ofstream ostr(outFileOfstream);
    ostr << a;
    const EnjoLib::Str strOut = ostr.Str();
    CHECK_EQUAL("1", strOut);
}

TEST(Ofstream_carr)
{
    const char * carr = "dupa";
    Ofstream ostr(outFileOfstream);
    ostr << carr;
    const EnjoLib::Str strOut = ostr.Str();
    CHECK_EQUAL(carr, strOut.c_str());
}

TEST(Ofstream_char)
{
    const char carr = ' ';
    Ofstream ostr(outFileOfstream);
    ostr << carr;
    const EnjoLib::Str strOut = ostr.Str();
    CHECK_EQUAL(" ", strOut.c_str());
}
