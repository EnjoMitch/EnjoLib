#ifndef COUTBUF_H
#define COUTBUF_H


#include <Ios/Osstream.hpp>
#include <Ios/Cout.hpp>
#include <3rdParty/stdfwd.hh>

namespace EnjoLib
{

class LogBuf
{
    public:
        LogBuf(bool verbose = true);
        virtual ~LogBuf();
        
        void Flush();

        Ostream & GetLog();

    private:
        //SafePtrFast<std::ostream> m_cnull;
        //std::wostream m_wcnull;
        Osstream m_ostr;
        bool m_verbose;
};

class Log
{
    public:
        Log();
        virtual ~Log();

        Ostream & GetLog();

    private:
        Cout m_cout;
};

}


extern std::ostream cnull;
//extern std::wostream wcnull;

std::ostream & GetLog(bool verbose);

/// Create a buffered log object "logLocal" with optional disabled logging.
/**
The log will be displayed on the destruction of the object, but may be flushed before.
Usage:
ELOG // or ELOG(verbose)
LOG << "Text" << EnjoLib::Nl;
LOG_FLUSH // optional flushing
*/
#define ELOG(verbose) EnjoLib::LogBuf logLocal(verbose); 
/// Create a buffered log object logLocal with enabled logging
#define ELO ELOG(true)
#define LOG logLocal.GetLog()
#define LOG_FLUSH logLocal.Flush()

/// Create a non buffered log object "logLocal".
/**
No need to flush it, but it needs to be wraped in braces, if it's expected to be reused.
Usage:
LOGL << "Text" << EnjoLib::Nl;
or:
{LOGL << "Text1" << EnjoLib::Nl;}
{LOGL << "Text2" << EnjoLib::Nl;}
*/
#define LOGL EnjoLib::Log logLocal; logLocal.GetLog()


#endif // COUTBUF_H
