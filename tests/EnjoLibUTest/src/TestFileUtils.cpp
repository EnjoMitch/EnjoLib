#include "pch_test.h"

#include <UnitTest++/UnitTest++.h>
#include <Util/FileUtils.hpp>

using namespace std;
using namespace EnjoLib;

TEST(FileUtils_basedir)
{
    EnjoLib::Str basedirExp = "/tmp/test";
    EnjoLib::Str fullPath = basedirExp + "/testFile";
    EnjoLib::Str basedirRet = FileUtils().GetBaseDir(fullPath);
    CHECK_EQUAL(basedirExp, basedirRet);
}
