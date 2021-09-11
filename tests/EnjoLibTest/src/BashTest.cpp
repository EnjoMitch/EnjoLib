#include "BashTest.h"
#include <Util/CoutBuf.hpp>

#include <ctime>

using namespace std;
using namespace EnjoLib;

BashTest::BashTest()
{
    ELO

   std::time_t result = std::time(NULL);
   const std::tm* t =  std::localtime(&result);
   if(t->tm_wday == 1 and t->tm_mday <= 7)
    LOG << "true" << Endl;
    else
    LOG << "false" << Endl;

    LOG << "Today = " << t->tm_wday << Endl;
}

BashTest::~BashTest()
{
    //dtor
}

