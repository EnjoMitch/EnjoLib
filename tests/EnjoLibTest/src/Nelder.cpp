#include "Nelder.h"

#include <STD/Iostream.hpp>

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
        cout << "Rosenbrock Nelder = " << res.value.at(0) << ", " << res.value.at(1) << endl;
    }
    {
        OptiMultiRosenbrok subj;
        Result<VecD > res = OptiMultiBinSearch().Run( subj, 50, 0.0001 );
        cout << "Rosenbrock BinSer = " << res.value.at(0) << ", " << res.value.at(1) << endl;
    }



}
