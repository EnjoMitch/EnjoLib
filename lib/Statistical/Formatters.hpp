#ifndef FORMATTERS_H
#define FORMATTERS_H

#include <Util/Str.hpp>
#include <Util/VecD.hpp>

namespace EnjoLib {
class Formatters
{
    public:
        Formatters(int precision = 3);
        virtual ~Formatters();

        EnjoLib::Str FormatVar(const double var, bool color = false, int prec = -1) const;
        EnjoLib::Str FormatVec(const VecD & vec, bool color = false, double multiplier = 1) const;
        EnjoLib::Str VecLabel() const;

    protected:

    private:
        int m_precision;
};
}

#endif // FORMATTERS_H
