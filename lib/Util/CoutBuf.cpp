#include <Util/CoutBuf.hpp>
#include <Util/Str.hpp>
#include <STD/Iostream.hpp>
#include <STD/Ostream.hpp>

using namespace std;
using namespace EnjoLib;

std::ostream cnull(0);
//std::wostream wcnull(0);

std::ostream & GetLog(bool verbose)
{
    if (verbose)
        return std::cout;
    else
        //return std::cout;
        return cnull;
}

/*
struct EnjoLib::LogImpl
{
    LogImpl()
    : m_cnull(0)
    , m_wcnull(0)
    {
    }
    std::ostream m_cnull;
    std::wostream m_wcnull;
};
*/
LogBuf::LogBuf(bool verbose)
//: m_impl(new LogBufImpl())
//: m_cnull(0)
//, m_wcnull(0)
: m_verbose(verbose)
{
}

LogBuf::~LogBuf()
{
    Flush();
}

void LogBuf::Flush()
{
    if (m_verbose)
    {
        const Str str = m_ostr.str();
        if (not str.empty())
        {
            std::cout << str;
            m_ostr.Clear();
        }
    }
}

/*
std::ostream & LogBuf::GetLog(bool verbose)
{
    if (verbose)
        return std::cout;
    else
        //return std::cout;
        return *m_cnull;
}
*/

Ostream & LogBuf::GetLog()
{
    return m_ostr;
}

Log::Log(){}
Log::~Log(){}

Ostream & Log::GetLog()
{
    return m_cout;
}
