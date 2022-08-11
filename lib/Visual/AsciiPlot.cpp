#include <Visual/AsciiPlot.hpp>

#include <Visual/AsciiMisc.hpp>
#include <Ios/Osstream.hpp>
#include <Util/CoutBuf.hpp>
#include <Util/StrColour.hpp>
#include <Math/GeneralMath.hpp>
#include <Math/MaxMinFind.hpp>
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
    Add(Pars::HEATMAP, true);
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

EnjoLib::VecD AsciiPlot::Compress(const EnjoLib::VecD & vec) const
{
    return AsciiPlotGuts().Compress(vec, Get(Pars::COMPRESS), Get(Pars::COMPRESS_TYPE));
}

EnjoLib::VecD AsciiPlotGuts::Compress(const EnjoLib::VecD & vec, unsigned maxLen, int type) const
{
    //LOGL << "Max len " << maxLen << Nl;
    if (maxLen == 0)
    {
        return vec;
    }
    if (vec.size() < maxLen)
    {
        return vec;
    }
    VecD ret;
    const int numBins = maxLen + 1;
    
    /// TODO: It's the same pattern as in Distrib.cpp
    const FP lo = 0;
    const FP hi = vec.size() + 1;
    const FP rangeDiff = hi - lo;
    const FP binLen = rangeDiff / FP(numBins);
    //const int nbinLo = gm.round((lo-rangeLo) / binLen);
    //const int nbinHi = gm.round((hi-rangeLo) / binLen);

    for (int i = 1; i < numBins; ++i)
    {
        const FP valMin = lo + binLen * (i - 1);
        const FP valMax = lo + binLen * (i);
        const FP valMid = (valMax + valMin) / 2.0;
        int numOcurrences = 0;
        int j = 0;
        FP sum = 0;
        MaxMinFind<FP> mmf;
        for (const FP & val : vec)
        {
            if (Assertions::InFast(valMin, j, valMax))
            {
                if (type == 0)
                {
                    sum += val;
                    ++numOcurrences;
                }
                else
                {
                    mmf.UpdateMaxMin(val);
                }
                
            }
            ++j;
        }
        FP valFin;
        if (type > 0)
        {
           valFin = mmf.GetMax(); 
        }
        else if (type < 0)
        {
           valFin = mmf.GetMin(); 
        }
        else // (type == 0)
        {
            if (numOcurrences == 0)
            {
                Assertions::Throw("numOcurrences == 0", "AsciiPlot::Compress");
            }
            const FP average = sum / FP(numOcurrences);
            valFin = average;
        }
        ret.push_back(valFin);
        
    }
    return ret;
    
    return VecD(maxLen);
    return vec;
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
    const int len0 = confLoc.Compress(mat.at(0)).size();
    const bool decoration = confLoc.Get(AsciiPlot::Pars::DECORATION);
    const Str & deco = decoration ? (" " + AsciiMisc().GenChars("–", len0 + 2) + Nl) : "";
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
    if (color)
    {
        if (not useNegativeBlocks)
        {
            if (val > maximum)
            {
                ret = StrColour::GenNorm(StrColour::Col::Red, ret);
            }
            else
            {
                ret = StrColour::GenNorm(StrColour::Col::Green, ret);
            }
        }
    }
    else
    {
        if (val > maximum)
        {
            // Something to decide later
            //ret = StrColour::GenNorm(StrColour::Col::Red, ret);
        }
    }
    return ret;
}

EnjoLib::Str AsciiPlotGuts::GetPercentToAscii(const EnjoLib::VecD & valsOrig, const AsciiPlot & conf, double minimum, double maximum) const
{
    const EnjoLib::VecD & vals = conf.Compress(valsOrig);
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
