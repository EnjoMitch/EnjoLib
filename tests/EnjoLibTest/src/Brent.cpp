#include "Brent.h"

#include <Math/Opti/OptiFactory.hpp>
#include <Math/Opti/OptiSubject.hpp>
#include <Template/CorradePointer.h>

#include <cmath>
#include <STD/Iostream.hpp>
#include <iomanip>

using namespace std;
using namespace EnjoLib;

Brent::Brent()
{
    //ctor
}

Brent::~Brent()
{
    //dtor
}

class g_04 : public OptiSubject
{
public:
    double UpdateGetValue( double arg )
    {
       return std::exp ( arg ) + 0.01 / arg;
    }
     //
};

class xx : public OptiSubject
{
public:
    double UpdateGetValue( double arg )
    {
       return arg * arg;
    }
     //
};

void Brent::Run() const
{
        //double a =  0.0001;
    //double b =  1.0;
    double t = 0.1;

    double a =  -11;
    double b =  +15;
    xx subj;
    //test_local_min_one ( a, b, t, subj, "g_04(x) = exp ( x ) + 1 / ( 100 x )" );
    test_local_min_one ( a, b, t, subj, OPTI_BIN_SEARCH, "f(x) = x^2" );
    test_local_min_one ( a, b, t, subj, OPTI_BRENT, "f(x) = x^2" );
}

//****************************************************************************80
void Brent::test_local_min_one ( double a, double b, double t, OptiSubject & subj, OptiType type,
                          const char * title ) const

//****************************************************************************80
//
//  Purpose:
//
//    TEST_LOCAL_MIN_ONE tests Brent's local minimizer on one test function.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double A, B, the endpoints of the interval.
//
//    Input, double T, a positive absolute error tolerance.
//
//    Input, double F ( double x ), the name of a user-supplied
//    function, whose local minimum is being sought.
//
//    Input, string TITLE, a title for the problem.
//
{
     Corrade::Containers::Pointer<IOptiAlgo> algo = OptiFactory::Create(type, a, b, t);
    cout << "Created" << endl;
    Result<double> res = algo->Run(subj);
    if (!res.isSuccess)
    {
        cout << "Failed to find optimum in given nr of iters." << endl;
    }
    double x = res.value;
    cout << "Ran" << endl;
    //fx = br.local_min ( a, b, t, f, x );
    double fa = subj.UpdateGetValue ( a );
    double fb = subj.UpdateGetValue ( b );
    double fx = subj.UpdateGetValue ( x );

    cout << setprecision(10);
    cout << "\n";
    cout << "  " << title << "\n";
    cout << "\n";
    cout << "           A                 X             B\n";
    cout << "         F(A)              F(X)          F(B)\n";
    cout << "  " << setw(14) << a
         << "  " << setw(14) << x
         << "  " << setw(14) << b << "\n";
    cout << "  " << setw(14) << fa
         << "  " << setw(14) << fx
         << "  " << setw(14) << fb << endl;

    return;
}
