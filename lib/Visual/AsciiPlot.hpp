#ifndef ASCIIPLOT_HPP
#define ASCIIPLOT_HPP

#include <Util/Str.hpp>
#include <Util/VecD.hpp>
#include <Template/BuilderTpl.hpp>

namespace EnjoLib {
class Matrix;

class AsciiPlot
{
public:
    enum class Pars
    {
        DECORATION,
        COLORS,
        BLOCKS,
        MULTILINE,
        HEATMAP,
        NEGATIVE,
        MINIMUM,
        MAXIMUM,
        WARNING,
        MAX_NUM_BINS,
        END
    };

    using BuilderT = BuilderTpl<AsciiPlot, Pars, double>;
    static BuilderT Build();

    AsciiPlot(const BuilderT & builder);
    virtual ~AsciiPlot();

    void Add(const Pars & key, double val);
    double Get(const Pars & key) const;

    Str Plot(const EnjoLib::VecD & val) const;
    Str Plot(const EnjoLib::Matrix & mat) const;

protected:
    AsciiPlot() {}
private:
    VecD m_pars;
};

class AsciiPlotGuts
{
public:
    using Pars = AsciiPlot::Pars;

    friend class AsciiPlot;

//private:
    EnjoLib::Str GetPercentToAsciiBlocks(double val, bool color = false) const;
    EnjoLib::Str GetPercentToAsciiBlocksPositive(double val) const;
    EnjoLib::Str GetPercentToAscii(double val, double minimum = 0, double maximum = 1, bool blocks = false, bool useNegativeBlocks = false, bool colors = true, bool heatmap = false) const;
    EnjoLib::Str GetPercentToAscii(const EnjoLib::VecD & val,   const AsciiPlot & conf, double minimum = 0, double maximum = 1) const;
    EnjoLib::Str GetPercentToAscii(const EnjoLib::Matrix & val, const AsciiPlot & conf, double minimum = 0, double maximum = 1) const;
    EnjoLib::Str GetMultiline() const;
    EnjoLib::Str GetMultiline(const EnjoLib::VecD & val, double minimum = 0, double maximum = 1) const;
};

}

#endif // ASCIIPLOT_HPP