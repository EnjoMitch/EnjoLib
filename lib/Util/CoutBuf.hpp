#ifndef COUTBUF_H
#define COUTBUF_H

#include <3rdParty/stdfwd.hh>
//#include <STD/Ostream.hpp>
#include <Util/Osstream.hpp>

namespace EnjoLib
{
//struct LogImpl;
class Log
{
    public:
        Log(bool verbose = true);
        virtual ~Log();

        Osstream & GetLog();

    private:
        //SafePtrFast<std::ostream> m_cnull;
        //std::wostream m_wcnull;
        Osstream m_ostr;
        bool m_verbose;
};
const char NL3 = '\n';
}


extern std::ostream cnull;
//extern std::wostream wcnull;

std::ostream & GetLog(bool verbose);

#define ELOG(verbose) EnjoLib::Log logLocal(verbose);
#define ELO ELOG(true)
#define LOG logLocal.GetLog()
#define LOGL ELO LOG
    

#endif // COUTBUF_H
