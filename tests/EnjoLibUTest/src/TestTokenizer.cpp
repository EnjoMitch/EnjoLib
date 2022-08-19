#include "pch_test.h"

#include <Util/Str.hpp>
#include <Util/Tokenizer.hpp>
#include <Util/ToolsMixed.hpp>
#include <Ios/Sstream.hpp>
#include <Ios/Ofstream.hpp>

#include <UnitTest++/UnitTest++.h>

using namespace EnjoLib;

TEST(GetLines_basic)
{
    Sstream sstr;
    sstr.SetStr("Bla\nBla2");

    const VecStr & lines = Tokenizer().GetLines(sstr);

    const int num = 2;
    CHECK_EQUAL(num,  lines.size());
}

TEST(GetLines_basic2)
{
    const Str tmpFile = ToolsMixed().GetTmpDir() + "/test-tokenizer.txt";
    VecStr content;
    content.push_back("a");
    content.push_back("b");
    {
        Ofstream ostr(tmpFile);
        for (auto & str : content)
            ostr << str << "\n";
    }

    const VecStr & lines = Tokenizer().GetLines(tmpFile);
    CHECK_EQUAL(content.size(), lines.size());

    CHECK(content == lines);

    //VecStr contentMod = contentMod; /// TODO: Crashes! Test case!
    //contentMod.atw(0) = "c";

    VecStr contentMod;
    contentMod.push_back("a");
    contentMod.push_back("c");
    CHECK(contentMod != lines);
}

TEST(FilterLines_comment)
{
    const Tokenizer tok;
    VecStr content;
    content.push_back("#a");
    content.push_back("b");
    const VecStr & filtered = tok.FilterLines(content);
    CHECK_EQUAL(filtered.size(), 1);
}

TEST(FilterLines_commentSpaces)
{
    const Tokenizer tok;
    VecStr content;
    content.push_back("   #a");
    content.push_back("b");
    const VecStr & filtered = tok.FilterLines(content);
    CHECK_EQUAL(filtered.size(), 1);
}

TEST(FilterLines_tabsSpaces)
{
    const Tokenizer tok;
    VecStr content;
    content.push_back("           a");
    content.push_back("b");
    const VecStr & filtered = tok.FilterLines(content);
    CHECK_EQUAL(filtered.size(), content.size());
    CHECK_EQUAL(filtered.at(0), Str("a"));
}

TEST(FilterLines_tabsSpacesMultiple)
{
    const Tokenizer tok;
    VecStr content;
    content.push_back("a      d    ");
    const VecStr & filtered = tok.FilterLines(content);
    CHECK_EQUAL(filtered.size(), content.size());
    CHECK_EQUAL(filtered.at(0), Str("a d"));
}

