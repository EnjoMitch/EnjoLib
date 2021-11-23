#include <Util/ThreadWrap.hpp>

#include <thread>
#include <chrono>

using namespace EnjoLib;

ThreadWrap::ThreadWrap()
{
    //ctor
}

ThreadWrap::~ThreadWrap()
{
    //dtor
}

int ThreadWrap::GetConcurrency()
{
    return std::thread::hardware_concurrency();
}

void ThreadWrap::SleepForMilliseconds(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void ThreadWrap::Yield()
{
    std::this_thread::yield();
}
