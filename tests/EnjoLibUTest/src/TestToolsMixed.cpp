#include "pch_test.h"

#include <Util/ToolsMixed.hpp>
#include <Util/CoutBuf.hpp>
#include <Util/VecD.hpp>
#include <Math/RandomMath.hpp>
#include <Statistical/Distrib.hpp>
#include <Statistical/Matrix.hpp>
#include <Visual/AsciiMisc.hpp>
#include <Visual/AsciiPlot.hpp>

#include <UnitTest++/UnitTest++.h>

using namespace EnjoLib;

TEST(Gen_lines_1)
{
    double inp = 30.1;
    Str exp = "[===       ]";

    const Str & ret = AsciiMisc().GenBars10(inp);
    CHECK_EQUAL(exp, ret);
}

TEST(Gen_lines_95)
{
    double inp = 95.1;
    Str exp = "[==========]";

    const Str & ret = AsciiMisc().GenBars10(inp);
    CHECK_EQUAL(exp, ret);
}

TEST(Gen_lines_111)
{
    double inp = 111;
    Str exp = "[==========]";

    const Str & ret = AsciiMisc().GenBars10(inp);
    CHECK_EQUAL(exp, ret);
}

static VecD GetInputAscii()
{
    VecD inp;
    for (int i = 4; i >= -6; --i)
    {
        inp.Add(i);
    }
    for (int i = 0; i <= 16; ++i)
    {
        inp.Add(i);
    }
    return inp;
}

TEST(MixUtils_values_to_ascii1)
{
    const VecD & inp = GetInputAscii();
    //const double minimum = 0;
    const double maximum = inp.Max() - 2;

    const Str ret = AsciiPlot::Build()(AsciiPlot::Pars::MAXIMUM, maximum).Finalize().Plot(inp);
    CHECK(ret.size());
    LOGL << "values_to_ascii1:" << Nl << ret << Nl;
}

TEST(MixUtils_multipline)
{
    const VecD & inp = GetInputAscii();
    //const double minimum = 0;
    const double maximum = inp.Max() - 2;

    const Str ret = AsciiPlot::Build()(AsciiPlot::Pars::MAXIMUM, maximum)
    (AsciiPlot::Pars::MULTILINE, true).Finalize().Plot(inp);
    CHECK(ret.size());
    LOGL << "multiline:" << Nl << ret << Nl;
}

TEST(MixUtils_values_to_ascii_char)
{
    CHECK_EQUAL("▁",                     AsciiPlotGuts().GetPercentToAsciiBlocks( 1/4.0 * 0.99));
    CHECK_EQUAL("\033[2;47;30m▆\033[0m", AsciiPlotGuts().GetPercentToAsciiBlocks(-1/4.0 * 0.99));
    CHECK_EQUAL("▅",                     AsciiPlotGuts().GetPercentToAsciiBlocks( 3/4.0 * 0.99));
    CHECK_EQUAL("\033[2;47;30m▂\033[0m", AsciiPlotGuts().GetPercentToAsciiBlocks(-3/4.0 * 0.99));
}


TEST(Distrib_test_plot_matrix)
{
    const RandomMath rmath;
    const Distrib distr;

    Matrix matTmp;
    VecD data;
    const double minimum = 0.01;
    double maximum = 1;
    const double maxJ = 5;
    for (int j = 0; j < maxJ; ++j)
    {
        //VecD data;
        for (int i = 0; i < 2e4; ++i)
        {
            data.push_back(rmath.SampleNormal());
        }
        const DistribData & distData = distr.GetDistrib(data, 40);
        const VecD & daty = distData.GetY();
        matTmp.Add(daty);
        maximum = daty.Max();
    }
    Matrix mat = matTmp;
    for (int j = maxJ - 1; j >= 0; --j)
    {
        mat.Add(matTmp.at(j));
    }

    const Str ret = AsciiPlot::Build()
    (AsciiPlot::Pars::MINIMUM, minimum)
    (AsciiPlot::Pars::MAXIMUM, maximum)
    .Finalize().Plot(mat);
    CHECK(ret.size());
    LOGL << "Matrix heatmap:" << Nl << ret << Nl;
}

TEST(AsciiPlot_builder_1)
{
    ELO
    LOG << "\nBuilder" << Nl;

    const VecD & inp = GetInputAscii();
    const double maximum = inp.Max() - 2;

    using Par = AsciiPlot::Pars;
    LOG << AsciiPlot::Build()
    (Par::COLORS, true)(Par::DECORATION, false)(Par::MAXIMUM, maximum)(Par::BLOCKS, true).
    Finalize().Plot(inp) << Nl;

}

