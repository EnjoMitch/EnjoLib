#include <Math/RandomMath.hpp>

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

/// Box-Muller. TODO: add min and max values of the range
double RandomMath::SampleNormal() const
{
    const double u = ((double) rand() / (RAND_MAX)) * 2 - 1;
    const double v = ((double) rand() / (RAND_MAX)) * 2 - 1;
    //const double u = Rand(min, max);
    //const double v = Rand(min, max);
    const double r = u * u + v * v;
    if (r == 0 || r > 1) return SampleNormal();
    const double c = sqrt(-2 * log(r) / r);
    return u * c;
}
