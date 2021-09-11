#include "Nelder.h"

#include <Util/CoutBuf.hpp>
#include <Math/Opti/OptiMultiNelderMead.hpp>
#include <Math/Opti/OptiMultiBinSearch.hpp>
#include "OptiMultiRosenbrok.h"


using namespace std;
using namespace EnjoLib;

Nelder::Nelder(){}
Nelder::~Nelder(){}



//****************************************************************************80

void Nelder::Run() const
{
    {
        OptiMultiRosenbrok subj;
        Result<VecD > res = OptiMultiNelderMead().Run( subj );
        LOGL << "Rosenbrock Nelder = " << res.value.at(0) << ", " << res.value.at(1) << Endl;
    }
    {
        OptiMultiRosenbrok subj;
        Result<VecD > res = OptiMultiBinSearch().Run( subj, 50, 0.0001 );
        LOGL << "Rosenbrock BinSer = " << res.value.at(0) << ", " << res.value.at(1) << Endl;
    }
}
