#include "CoutBufTestEL.h"
#include <Util/CoutBuf.hpp>

CoutBufTestEL::CoutBufTestEL()
{
    {
        EnjoLib::Log log(true);
        log.GetLog() << "COUT BUF TEST2\n";
    }
    {
        EnjoLib::Log log(false);
        log.GetLog() << "I shouldn't be displayed\n";
    }
    
    {
        ELOG(true)
        LOG << "COUT BUF TEST3\n";
    }
}

CoutBufTestEL::~CoutBufTestEL()
{
    //dtor
}
