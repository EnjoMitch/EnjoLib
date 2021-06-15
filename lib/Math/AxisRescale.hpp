#ifndef AXISRESCALE_H
#define AXISRESCALE_H

#include <utility>

namespace EnjoLib
{
class AxisRescale
{
    public:
        typedef std::pair<double, double> PairD;
        AxisRescale(const PairD & axisStartEndFrom,
                    const PairD & axisStartEndTo);
        virtual ~AxisRescale(){}

        bool IsValid() const;
        double operator()(double pointOnInputScale) const;


    protected:

    private:
        double m_axisInMin;
        double m_axisInMax;
        double m_axisOutMin;
        double m_axisOutMax;

        double m_lenIn;
        double m_lenOut;
};
}


#endif // AXISRESCALE_H
