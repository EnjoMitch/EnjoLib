#include <Visual/AsciiPlot.hpp>

#include <Visual/AsciiMisc.hpp>
#include <Ios/Osstream.hpp>
#include <Util/StrColour.hpp>
#include <Math/GeneralMath.hpp>
#include <Statistical/Assertions.hpp>
#include <Statistical/Matrix.hpp>

using namespace EnjoLib;

/*
bool decoration = false;
bool colors = true;
bool blocks = true;
bool heatmap = false;
bool negativeBlocks = false;
double minimum = 0;
double maximum = 1;
double warning = maximum;
int maxNumBins = 40; /// TODO: compress like drawdown
*/

AsciiPlot::~AsciiPlot(){}
AsciiPlot:: AsciiPlot(const BuilderT & builder)
: m_pars(static_cast<int>(Pars::END))
{
    Add(Pars::MAXIMUM, 1);
    Add(Pars::BLOCKS, true);
    Add(Pars::MAX_NUM_BINS, 40);
}

Str AsciiPlot::Plot(const EnjoLib::VecD & val) const
{
    /// TODO: Finalize and ditch AsciiPlotGuts
    //AsciiPlotGuts cfg;
    //cfg.colors = Get(Pars::COLORS);
    //cfg.decoration = Get(Pars::DECORATION);
    //LOGL << "Colors = " << cfg.colors << Nl;
    return AsciiPlotGuts().GetPercentToAscii(val, *this, Get(Pars::MINIMUM), Get(Pars::MAXIMUM));
}

Str AsciiPlot::Plot(const EnjoLib::Matrix & mat) const
{
    return AsciiPlotGuts().GetPercentToAscii(mat, *this, Get(Pars::MINIMUM), Get(Pars::MAXIMUM));
}

AsciiPlot::BuilderT AsciiPlot::Build()
{
    return BuilderT();
}

void AsciiPlot::Add(const Pars & key, double val)
{
    m_pars.at(static_cast<int>(key)) = val;
}

double AsciiPlot::Get(const Pars & key) const
{
    return m_pars.at(static_cast<int>(key));
}

static EnjoLib::Str Inv(const EnjoLib::Str & str, bool color = false)
{
    const Str strCol = color ? "41" : "47";
    return "\033[2;" + strCol + ";30m" + str + "\033[0m";
}

EnjoLib::Str AsciiPlotGuts::GetMultiline(const EnjoLib::VecD & vec, double minimum, double maximum) const
{
    EnjoLib::Str line1, line2, ret;
    bool color = true;
    for (const double val : vec)
    {
        const double pro = GMat().ScaleVal(val, minimum, maximum);
        if (val >= 0)
        {
            const Str txtPositive = GetPercentToAsciiBlocksPositive(pro);
            const StrColour::Col color = val <= maximum ? StrColour::Col::Green : StrColour::Col::Red;

            line1 += StrColour::GenNorm(color, txtPositive);
            line2 +=" ";
        }
        else
        {
            line1 += " ";
            line2 += GetPercentToAsciiBlocks(pro, color);
        }
    }
    ret = line1 + "\n" + line2;
    return ret;
    //return ret.str();
}

EnjoLib::Str AsciiPlotGuts::GetPercentToAscii(const EnjoLib::Matrix & mat, const AsciiPlot & conf, double minimum, double maximum) const
{
    EnjoLib::Osstream ret;
    AsciiPlot confLoc = conf;
    confLoc.Add(AsciiPlot::Pars::DECORATION, true);
    confLoc.Add(AsciiPlot::Pars::HEATMAP,    true);
    confLoc.Add(AsciiPlot::Pars::BLOCKS,     false);
    //confLoc.decoration = true;
    //confLoc.blocks = false;
    //confLoc.colors = false;
    //confLoc.heatmap = true;
    const bool decoration = confLoc.Get(AsciiPlot::Pars::DECORATION);
    const Str & deco = decoration ? (" " + AsciiMisc().GenChars("–", mat.at(0).size() + 2) + Nl) : "";
    ret << deco;
    for (const VecD & vec : mat)
    {
        ret << GetPercentToAscii(vec, confLoc, minimum, maximum) << Nl;
    }
    ret << deco;
    return ret.str();
}


EnjoLib::Str AsciiPlotGuts::GetPercentToAsciiBlocks(double pro, bool color) const
{
    if (pro >= 0)
    {
        return GetPercentToAsciiBlocksPositive(pro);
    }

    const double proPositive = 1 + pro; // a subtraction
    //LOGL << pro << ". proPositive = " << proPositive << Nl;
    //const double proPositiveCorrected = proPositive > 1 ?;
    const Str strPositive = GetPercentToAsciiBlocksPositive(proPositive);
    const Str strInv = Inv(strPositive, color);

    return strInv;
}

EnjoLib::Str AsciiPlotGuts::GetPercentToAsciiBlocksPositive(double pro) const
{
    EnjoLib::Str ret = "";
    // https://de.wikipedia.org/wiki/Unicodeblock_Blockelemente
    if (pro < 0)
    {
        ret = " ";
    }
    else if (0 <= pro && pro < 1/8.0)
    {
        ret = "_";
    }
    else if (1/8.0 <= pro && pro < 1/4.0)
    {
        ret = "▁";
    }
    else if (1/4.0 <= pro && pro < 3/8.0)
    {
        ret = "▂";
    }
    else if (3/8.0 <= pro && pro < 1/2.0)
    {
        ret = "▃";
    }
    else if (1/2.0 <= pro && pro < 5/8.0)
    {
        ret = "▄";
    }
    else if (5/8.0 <= pro && pro < 3/4.0)
    {
        ret = "▅";
    }
    else if (3/4.0 <= pro && pro < 7/8.0)
    {
        ret = "▆";
    }
    else if (7/8.0 <= pro && pro < 1)
    {
        ret = "▇";
    }
    else
    {
        ret = "█";
        }
    return ret;
}

EnjoLib::Str AsciiPlotGuts::GetPercentToAscii(double val, double minimum, double maximum, bool blocks, bool useNegativeBlocks, bool color, bool heatmap) const
{
    const double pro = GMat().ScaleVal(val, minimum, maximum);
    //LOGL << pro << Nl;
    EnjoLib::Str ret = "1";

    if (blocks)
    {
        if (useNegativeBlocks)
        {
            ret = GetPercentToAsciiBlocks(pro);
        }
        else
        {
            ret = GetPercentToAsciiBlocksPositive(pro);
        }
    }
    else
    {
        if (pro < 0)
        {
            ret = " ";
        }
        else if (0 <= pro && pro < 0.1)
        {
            ret = heatmap ? "·" : "_";
        }
        else if (0.1 <= pro && pro < 0.3)
        {
            ret = heatmap ? "◦" : ".";
        }
        else if (0.3 <= pro && pro < 0.5)
        {
            ret = "░";
        }
        else if (0.5 <= pro && pro < 0.7)
        {
            ret = "▒";
        }
        else if (0.7 <= pro && pro < 1)
        {
            ret = "▓";
        }
        else
        {
            ret = "█";
        }
    }

    return ret;
}

EnjoLib::Str AsciiPlotGuts::GetPercentToAscii(const EnjoLib::VecD & vals, const AsciiPlot & conf, double minimum, double maximum) const
{
    if (conf.Get(Pars::MULTILINE))
    {
        return GetMultiline(vals, minimum, maximum);
    }
    EnjoLib::Osstream oss;
    if (conf.Get(Pars::DECORATION))
    {
        oss << "├ ";
    }
    for (const double val : vals)
    {
        oss << GetPercentToAscii(val, minimum, maximum, conf.Get(Pars::BLOCKS), conf.Get(Pars::NEGATIVE),
                                 conf.Get(Pars::COLORS), conf.Get(Pars::HEATMAP));
    }
    if (conf.Get(Pars::DECORATION))
    {
        oss << " ┤";
    }
    return oss.str();
}