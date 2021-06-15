#include "RandomMath.hpp"
#include <random>
#include <ctime>

using namespace EnjoLib;

RandomMath:: RandomMath(){}
RandomMath::~RandomMath(){}

void RandomMath::RandSeed(int seed) const
{
    if (seed == 0)
        srand (time(NULL));
    else
        srand (seed);
}

double RandomMath::Rand(double min, double max) const
{
    const double val = rand() / static_cast<double>(RAND_MAX) * (max-min) + min;
    return val;
}
