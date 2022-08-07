#include "Rosenbrok.h"

Rosenbrok::Rosenbrok(){}
Rosenbrok::~Rosenbrok(){}

EnjoLib::FP Rosenbrok::Eval( const EnjoLib::FP x[2] ) const

//****************************************************************************80
//
//  Purpose:
//
//    ROSENBROCK evaluates the Rosenbrock parabolic value function.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 February 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    R ONeill,
//    Algorithm AS 47:
//    Function Minimization Using a Simplex Procedure,
//    Applied Statistics,
//    Volume 20, Number 3, 1971, pages 338-345.
//
//  Parameters:
//
//    Input, double X[2], the argument.
//
//    Output, double ROSENBROCK, the value of the function.
//
{
  EnjoLib::FP fx;
  EnjoLib::FP fx1;
  EnjoLib::FP fx2;

  fx1 = x[1] - x[0] * x[0];
  fx2 = 1.0 - x[0];

  fx = 100.0 * fx1 * fx1
     +         fx2 * fx2;

  return fx;
}
