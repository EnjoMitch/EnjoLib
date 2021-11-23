#ifndef THREADWRAP_H
#define THREADWRAP_H

namespace EnjoLib {
class ThreadWrap
{
    public:
        ThreadWrap();
        virtual ~ThreadWrap();

        static int GetConcurrency();
        static void SleepForMilliseconds(int milliseconds);
        static void Yield();

    protected:

    private:
};

}
#endif // THREADWRAP_H
