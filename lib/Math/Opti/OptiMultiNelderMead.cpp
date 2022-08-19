#include "OptiMultiNelderMead.hpp"
#include "../Burkardt/NelderMeadBurkardt.hpp"
#include "OptiMultiSubject.hpp"
#include "../../Statistical/Assertions.hpp"
//#include "../../Statistical/VectorD.hpp"
#include "../../Util/VecD.hpp"
#include <Util/CoutBuf.hpp>
#include <Util/Str.hpp>
#include <Ios/Osstream.hpp>
#include <Ios/IoManip.hpp>

using namespace std;
using namespace EnjoLib;

OptiMultiNelderMead::OptiMultiNelderMead()
{
    //ctor
}

OptiMultiNelderMead::~OptiMultiNelderMead(){}

Result<VecD > OptiMultiNelderMead::Run( OptiMultiSubject & subj, FP eps, int konvge, int kcount ) const
{
    bool verbose = false;
    //verbose = true;
    VecD xret;

    const VecD sta = subj.GetStart();
    const VecD ste = subj.GetStep();

    Assertions::SizesEqual(sta, ste, "start, step");

    // TODO: assertions!
    int i;
    int icount;
    int ifault;
    int n;
    int numres;
    FP *start;
    FP *step;
    FP *xmin;
    FP ynewlo;

    n = sta.size();

    start = new FP[n];
    step = new FP[n];
    xmin = new FP[n];

    for (i = 0; i < n; ++i)
    {
       start[i] = sta[i];
       step[i] = ste[i];
    }

    ynewlo = subj.Get( start, n );

    Osstream oss;
    if (verbose)
    {
        oss << "\n";
        oss << "TEST01\n";
        oss << "  Apply NELMIN to ROSENBROCK function.\n";


        oss << "\n";
        oss << "  Starting point X:\n";
        oss << "\n";
        for ( i = 0; i < n; i++ )
        {
            IoManip::SetW(oss, 14);
            oss << "  " << start[i] << "\n";
        }
        oss << "\n";
        oss << "  F(X) = " << ynewlo << "\n";
    }

    NelderMeadBurkardt::nelmin ( subj, n, start, xmin, &ynewlo, eps, step,
                                 konvge, kcount, &icount, &numres, &ifault );

    if (verbose)
    {
        oss << "\n";
        oss << "  Return code IFAULT = " << ifault << "\n";
        oss << "\n";
        oss << "  Estimate of minimizing value X*:\n";
        oss << "\n";
        for ( i = 0; i < n; i++ )
        {
            IoManip::SetW(oss, 14);
            oss << "  " << xmin[i] << "\n";
        }

        oss << "\n";
        oss << "  F(X*) = " << ynewlo << "\n";

        oss << "\n";
        oss << "  Number of iterations = " << icount << "\n";
        oss << "  Number of restarts =   " << numres << "\n";
        LOGL << oss.str();
    }
    delete [] start;
    delete [] step;


    for ( i = 0; i < n; i++ )
    {
        xret.push_back(xmin[i]);
    }
    Result<VecD > ret(xret, ifault == 0);

    delete [] xmin;
    return ret;
}
