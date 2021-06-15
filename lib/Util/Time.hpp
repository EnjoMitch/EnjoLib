#ifndef TIME_H
#define TIME_H

#include <Util/Str.hpp>
#include <ctime>

namespace EnjoLib
{
class Time
{
    public:
        Time();
        virtual ~Time();

        EnjoLib::Str CurrentDateTime() const;
        EnjoLib::Str CurrentTime() const;
        EnjoLib::Str CurrentDateTimeFormated(const EnjoLib::Str & format) const;
        EnjoLib::Str TimeStampToHuman(const time_t rawtime) const;
        EnjoLib::Str TimeStampToHuman(const time_t rawtime, const EnjoLib::Str & format) const;
        bool IsWeekend() const;


    protected:
    private:
};
}
#endif // TIME_H
