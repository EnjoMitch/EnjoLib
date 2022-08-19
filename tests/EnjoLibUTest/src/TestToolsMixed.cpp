#include "pch_test.h"

#include <Util/Str.hpp>
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

    const Str ret = AsciiPlot::Build()(AsciiPlot::Pars::MAXIMUM, maximum)
    (AsciiPlot::Pars::COLORS, true)
    .Finalize().Plot(inp);
    CHECK(ret.size());
    LOGL << "to_ascii1:\n" << ret << Nl;
}

TEST(MixUtils_multipline)
{
    const VecD & inp = GetInputAscii();
    //const double minimum = 0;
    const double maximum = inp.Max() - 2;

    const Str ret = AsciiPlot::Build()(AsciiPlot::Pars::MAXIMUM, maximum)
    (AsciiPlot::Pars::MULTILINE, true).Finalize().Plot(inp);
    CHECK(ret.size());
    LOGL << "multiline:\n" << ret << Nl;
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
    const double maxJ = 3;
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
    LOG << "Builder\t\t";

    const VecD & inp = GetInputAscii();
    const double maximum = inp.Max() - 2;

    using Par = AsciiPlot::Pars;
    LOG << AsciiPlot::Build()
    (Par::COLORS, true)(Par::DECORATION, false)(Par::MAXIMUM, maximum)(Par::BLOCKS, true).
    Finalize().Plot(inp) << Nl;
}


TEST(AsciiPlot_grayscale_1)
{
    ELO
    LOG << "Greyscale\t";
    
    const VecD & inp = GetInputAscii();
    const double maximum = inp.Max() - 2;

    using Par = AsciiPlot::Pars;
    LOG << AsciiPlot::Build()
    (Par::MAXIMUM, maximum)(Par::BLOCKS, false)(Par::HEATMAP, false)
    .Finalize().Plot(inp) << Nl;
}

TEST(AsciiPlot_grayscale_2)
{
    ELO
    LOG << "Grey-heat\t";

    const VecD & inp = GetInputAscii();
    const double maximum = inp.Max() - 2;

    using Par = AsciiPlot::Pars;
    LOG << AsciiPlot::Build()
    (Par::MAXIMUM, maximum)(Par::BLOCKS, false).
    Finalize().Plot(inp) << Nl;
}


TEST(AsciiPlot_compress)
{
    ELO
    LOG << "Compressed\t";

    const VecD & inp = GetInputAscii();
    const double maximum = inp.Max() - 2;
    const int maxSize = 18;
    using Par = AsciiPlot::Pars;
    auto builder = AsciiPlot::Build()
    (Par::DECORATION, false)(Par::MAXIMUM, maximum)(Par::BLOCKS, true)(Par::COMPRESS, maxSize);
    
    const AsciiPlot & plot = builder.Finalize();
    const Str ret = plot.Plot(inp);
    LOG << ret << Nl;
    
    
    const VecD & inpCompr = plot.Compress(inp);
    CHECK_EQUAL(maxSize, inpCompr.size());
    CHECK_CLOSE(inp.Mean(), inpCompr.Mean(), 0.5);
    
    
    const AsciiPlot & plotMin = builder(Par::COMPRESS_TYPE, -1).Finalize();
    const AsciiPlot & plotMax = builder(Par::COMPRESS_TYPE, +1)(Par::COLORS, true).Finalize();
    
    const VecD & inpComprMax = plotMax.Compress(inp);
    const VecD & inpComprMin = plotMin.Compress(inp);
    
    LOG << "Compr max\t" << plotMax.Plot(inp) << Nl;
    LOG << "Compr min\t" << plotMin.Plot(inp) << Nl;

    CHECK_CLOSE(inp.Max(), inpComprMax.Max(), 0.01);
    CHECK_CLOSE(inp.Min(), inpComprMin.Min(), 0.01);
}
