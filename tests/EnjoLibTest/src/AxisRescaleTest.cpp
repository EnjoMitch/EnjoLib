#include "AxisRescaleTest.h"

#include <Math/AxisRescale.hpp>
#include <Util/CoutBuf.hpp>

using namespace EnjoLib;
using namespace std;

void AxisRescaleTest::Run() const
{
    {
        AxisRescale::PairD ainp(0, 5);
        AxisRescale::PairD aout(0, 10);
        const AxisRescale resc(ainp, aout);
        LOGL << resc(2.5)<< " = Should be 5" << Endl;
    }
    {
        AxisRescale::PairD ainp(1, 6);
        AxisRescale::PairD aout(0, 10);
        const AxisRescale resc(ainp, aout);
        LOGL << resc(3.5)<< " = Should be 5" << Endl;
    }
    {
        AxisRescale::PairD ainp(0, 5);
        AxisRescale::PairD aout(1, 11);
        const AxisRescale resc(ainp, aout);
        LOGL << resc(2.5)<< " = Should be 6" << Endl;
    }
    {
        AxisRescale::PairD ainp(1, 6);
        AxisRescale::PairD aout(1, 11);
        const AxisRescale resc(ainp, aout);
        LOGL << resc(3.5)<< " = Should be 6" << Endl;
    }
    {
        AxisRescale::PairD ainp(2, 7);
        AxisRescale::PairD aout(1, 11);
        const AxisRescale resc(ainp, aout);
        LOGL << resc(4.5)<< " = Should be 6" << Endl;
    }
    {
        AxisRescale::PairD ainp(1, 6);
        AxisRescale::PairD aout(1, 11);
        const AxisRescale resc(ainp, aout);
        LOGL << resc(6)<< " = Should be 11" << Endl;
    }

}
