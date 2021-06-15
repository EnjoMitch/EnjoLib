#ifndef LOSSFUNCTIONS_H
#define LOSSFUNCTIONS_H

#include "Util/VecD.hpp"

namespace EnjoLib
{
class LossFunctions
{
    public:
        LossFunctions();
        virtual ~LossFunctions();

        double GetMAE(const EnjoLib::VecD & diffs) const;
        double GetRMS(const EnjoLib::VecD & diffs) const;
        double GetHuber(const EnjoLib::VecD & diffs, const double delta) const;
        double GetLogCosh(const EnjoLib::VecD & diffs) const;
        double GetQuantileMAE(const EnjoLib::VecD & diffs, const double quantile) const;

    protected:

    private:
};
}

#endif // LOSSFUNCTIONS_H
