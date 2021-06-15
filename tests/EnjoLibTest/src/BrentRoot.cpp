#include "BrentRoot.h"
#include <Math/Root/RootSubject.hpp>
#include <Math/Root/RootFactory.hpp>
#include <Template/CorradePointer.h>
#include <STD/Iostream.hpp>
#include <iomanip>

#include <cmath>
using namespace std;
using namespace EnjoLib;

BrentRoot::BrentRoot()
{
    //ctor
}

BrentRoot::~BrentRoot()
{
    //dtor
}

class F_01 : public RootSubject
{
    double GetRefValue() const override { return 0; }
    /// Should return the function's value for a given argument.
    virtual double UpdateGetValue( double x ) override { return sin ( x ) - 0.5 * x; }
};
class F_02 : public RootSubject
{
    double GetRefValue() const override { return 0; }
    /// Should return the function's value for a given argument.
    virtual double UpdateGetValue( double x ) override { return 2.0 * x - exp ( - x ); }
};
class F_03 : public RootSubject
{
    double GetRefValue() const override { return 0; }
    /// Should return the function's value for a given argument.
    virtual double UpdateGetValue( double x ) override { return x * exp ( - x ); }
};
class F_04 : public RootSubject
{
    double GetRefValue() const override { return 0; }
    /// Should return the function's value for a given argument.
    virtual double UpdateGetValue( double x ) override { return exp ( x ) - 1.0 / 100.0 / x / x; }
};
class F_05 : public RootSubject
{
    double GetRefValue() const override { return 0; }
    /// Should return the function's value for a given argument.
    virtual double UpdateGetValue( double x ) override { return ( x + 3.0 ) * ( x - 1.0 ) * ( x - 1.0 ); }
};

void BrentRoot::Run() const
{
    Run(ROOT_BIN_SEARCH);
    Run(ROOT_BRENT);
}

void BrentRoot::Run( EnjoLib::RootType type ) const

//****************************************************************************80
//
//  Purpose:
//
//    TEST_ZERO_ALL tests Brent's zero finding routine on all test functions.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 July 2011
//
//  Author:
//
//    John Burkardt
//
{
    double a;
    double b;
    double t;

    cout << "\n";
    cout << "TEST_ZERO_ALL\n";
    cout << "  Test the Brent ZERO routine, which seeks\n";
    cout << "  a root of a function F(X)\n";
    cout << "  in an interval [A,B].\n";

    //t = r8_epsilon ( );
    //t = 0.00000000000001;
    t = 1E-015;

    a = 1.0;
    b = 2.0;



    F_01 f_01;
    F_02 f_02;
    F_03 f_03;
    F_04 f_04;
    F_05 f_05;
    test_zero_one ( a, b, t, f_01, type,
                    "f_01(x) = sin ( x ) - x / 2" );

    a = 0.0;
    b = 1.0;

    test_zero_one ( a, b, t, f_02, type,
                    "f_02(x) = 2 * x - exp ( - x )" );

    a = -1.0;
    b =  0.5;

    test_zero_one ( a, b, t, f_03, type,
                    "f_03(x) = x * exp ( - x )" );

    a =  0.0001;
    b =  20.0;

    test_zero_one ( a, b, t, f_04, type,
                    "f_04(x) = exp ( x ) - 1 / ( 100 * x * x )" );

    a = -5.0;
    b =  2.0;

    test_zero_one ( a, b, t, f_05, type,
                    "f_05(x) = (x+3) * (x-1) * (x-1)" );

    return;
}

void BrentRoot::test_zero_one ( double a, double b, double t, EnjoLib::RootSubject & subj, EnjoLib::RootType type, const char * title ) const
{
    double fa;
    double fb;
    double fz;
    double z;

    Corrade::Containers::Pointer<IRootAlgo> algo = RootFactory::Create(type, a,b,t);
    z = algo->Run( subj).value;
    fz = subj.UpdateGetValue( z );
    fa = subj.UpdateGetValue( a );
    fb = subj.UpdateGetValue( b );

    cout << "\n";
    cout << "  " << title << "\n";
    cout << "\n";
    cout << "           A                 Z             B\n";
    cout << "         F(A)              F(Z)          F(B)\n";
    cout << "  " << setw(14) << a
         << "  " << setw(14) << z
         << "  " << setw(14) << b << "\n";
    cout << "  " << setw(14) << fa
         << "  " << setw(14) << fz
         << "  " << setw(14) << fb << "\n";

    cout << "iter = " <<  algo->GetNumIterations() << endl;

    /*
    if (abs(fz) > check_tolerance)
    {
        cerr << "*** error ***" << endl;
        cerr << "fz " << fz
             << " exceeds check_tolerance " << check_tolerance << endl;
        exit(1);
    }
    */
    return;
}
