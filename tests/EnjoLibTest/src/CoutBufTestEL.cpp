#include "CoutBufTestEL.h"
#include <Util/CoutBuf.hpp>

#include <iostream>

CoutBufTestEL::CoutBufTestEL()
{
    {
        EnjoLib::LogBuf log(true);
        log.GetLog() << "COUT BUF TEST2" << EnjoLib::Nl;
    }
    {
        EnjoLib::LogBuf log(false);
        log.GetLog() << "I shouldn't be displayed" << EnjoLib::Nl;
    }
    
    {
        ELOG(true)
        LOG << "COUT BUF TEST3" << EnjoLib::Nl;
    }
    {
        LOGL << "COUT BUF First" << EnjoLib::Endl;
        std::cout << "COUT BUF Second" << std::endl;
    }
}

CoutBufTestEL::~CoutBufTestEL()
{
    //dtor
}
