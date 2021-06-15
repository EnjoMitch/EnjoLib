#ifndef TIMECOMPONENTS_H
#define TIMECOMPONENTS_H

#include <Util/Str.hpp>

namespace EnjoLib
{
class TimeComponents
{
    public:
        TimeComponents(double seconds);
        virtual ~TimeComponents();

        EnjoLib::Str ToString() const;

    protected:

    private:
        EnjoLib::Str MakeStr();

        double m_seconds;
        int m_minutes;
        int m_hours;
        EnjoLib::Str m_str;
};
}
#endif // TIMECOMPONENTS_H
