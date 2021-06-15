#ifndef STDDEV_H
#define STDDEV_H

namespace EnjoLib
{
class StdDev
{
    public:
        StdDev(double stdDev = 0);
        virtual ~StdDev(){}

        double GetValue() const;
        double GetVariance() const;

    protected:

    private:
        double m_stdDev = 0;
};
}
#endif // STDDEV_H
