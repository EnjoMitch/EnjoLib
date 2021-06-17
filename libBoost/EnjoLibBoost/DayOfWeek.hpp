#ifndef DAYOFWEEK_H
#define DAYOFWEEK_H

namespace EnjoLib
{
class DayOfWeek
{
    public:
        DayOfWeek(int year, int month, int day);
        virtual ~DayOfWeek();

        enum Day
        {
            Sunday,
            Monday,
            Tuesday,
            Wednesday,
            Thursday,
            Friday,
            Saturday
        };

        Day GetDay() const;
        int GetDayInt() const;
        int GetWeekNumber() const;

    protected:

    private:

        int m_year, m_month, m_day;
};
}
#endif // DAYOFWEEK_H
