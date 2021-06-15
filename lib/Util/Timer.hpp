#ifndef TIMER_H
#define TIMER_H

#include <ctime>

namespace EnjoLib
{
class Timer
{
    public:
        Timer();
        virtual ~Timer();

        double GetElapsedSeconds() const;

    protected:

    private:
        std::clock_t tbegin;
};
}

#endif // TIMER_H
