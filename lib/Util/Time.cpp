#include "Time.hpp"

#include <Util/CoutBuf.hpp>

#include <cstdio>
#include <ctime>

using namespace std;
using namespace EnjoLib;

Time::Time(){}
Time::~Time(){}

// Get current time, format is mm:ss
EnjoLib::Str Time::CurrentTime() const
{
    return CurrentDateTimeFormated("%X");
}

// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
EnjoLib::Str Time::CurrentDateTime() const
{
    return CurrentDateTimeFormated("%Y-%m-%d %X");
}

EnjoLib::Str Time::CurrentDateTimeFormated(const EnjoLib::Str & format) const
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[256];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), format.c_str(), &tstruct);

    return buf;
}

EnjoLib::Str Time::TimeStampToHuman(const time_t rawtime) const
{
    return TimeStampToHuman(rawtime, "%Y-%m-%d %X");
}

EnjoLib::Str Time::TimeStampToHuman(const time_t rawtime, const EnjoLib::Str & format) const
{
    struct tm * dt;
    char buffer [80];
    dt = localtime(&rawtime);
    strftime(buffer, sizeof(buffer), format.c_str(), dt);
    return buffer;
}

bool Time::IsWeekend() const
{
    std::time_t result = std::time(NULL);
    const std::tm* t =  std::localtime(&result);
    return t->tm_wday == 6 || t->tm_wday == 0; // Saturday or Sunday
}
