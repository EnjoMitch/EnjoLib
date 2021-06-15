#include "Timer.hpp"

using namespace std;
using namespace EnjoLib;

Timer::~Timer(){}
Timer::Timer()
{
    tbegin = clock();
}

double Timer::GetElapsedSeconds() const
{
  clock_t tend = clock();
  double elapsed_secs = double(tend - tbegin) / double(CLOCKS_PER_SEC);
  return elapsed_secs;
}
