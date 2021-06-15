#ifndef RANDOMMATH_HPP
#define RANDOMMATH_HPP

namespace EnjoLib
{
class RandomMath
{
    public:
        RandomMath();
        virtual ~RandomMath();

        /// Get random number
        /** Remember to call RandSeed() once before!
        */
        double Rand(double min, double max) const;
        void RandSeed(int seed = 0) const;

    protected:

    private:
};
}

#endif // RANDOMMATH_HPP
