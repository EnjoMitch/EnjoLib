#include "DayOfWeek.hpp"

#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/date_defs.hpp>
#include <Util/Except.hpp>

using namespace boost::gregorian;
using namespace EnjoLib;

DayOfWeek::~DayOfWeek(){}
DayOfWeek::DayOfWeek(int year, int month, int day)
: m_year(year), m_month(month), m_day(day)
{
}


DayOfWeek::Day DayOfWeek::GetDay() const
{
    date dCurr(m_year, m_month, m_day);
    auto dowCurr = dCurr.day_of_week();

    switch (dowCurr)
    {
        case boost::date_time::weekdays::Sunday:
            return Sunday;
        case boost::date_time::weekdays::Monday:
            return Monday;
        case boost::date_time::weekdays::Tuesday:
            return Tuesday;
        case boost::date_time::weekdays::Wednesday:
            return Wednesday;
        case boost::date_time::weekdays::Thursday:
            return Thursday;
        case boost::date_time::weekdays::Friday:
            return Friday;
        case boost::date_time::weekdays::Saturday:
            return Saturday;
    }
    throw EnjoLib::ExceptLogicError("DayOfWeek::GetDay(): Invalid day provided");
}

int DayOfWeek::GetWeekNumber() const
{
    date dCurr(m_year, m_month, m_day);
    return dCurr.week_number();
}

int DayOfWeek::GetDayInt() const
{
    auto dowCurr = GetDay();
    switch (dowCurr)
    {
    case Sunday:
        return 0;
    case Monday:
        return 1;
    case Tuesday:
        return 2;
    case Wednesday:
        return 3;
    case Thursday:
        return 4;
    case Friday:
        return 5;
    case Saturday:
        return 6;
    }
    return -1;
}

