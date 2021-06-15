/*
Modified BSD License

This file is a part of Math package and originates from:
http://sf.net/projects/enjomitchsorbit

Copyright (c) 2011-2012, Szymon "Enjo" Ender
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <cmath>
#include <ctime>
#include "Constants.hpp"
#include "GeneralMath.hpp"
#include "SimpsonFunctor.hpp"
#include "../Systems/Point.hpp"

using namespace EnjoLib;
// Simpson integration
// a - starting argument of function
// b - ending argument of function
// function pointer (define your own function)
// epsilon - specific preision that you may want to set
double GeneralMath::SimpsonInt(double a, double b, const SimpsonFunctor & function, double epsilon) const
{
    double h, integ = 0, integ_prev = 1;
    int m = 2;
    do
    {
        double sum = 0;
        h = (b-a) / (double)(2.0*m);
        for ( int i = 1; i < 2*m; ++i )
        {
            if (i % 2) sum = sum + 4.0 * function(a + h*i);
            else sum = sum + 2.0 * function(a + h*i);
        }
        integ_prev = integ;
        integ = (h/3.0) * ( function(a) + sum + function(b) );
        m = m * 2;
    }
    while ( fabs(integ - integ_prev) > epsilon );
    return integ;
}

int GeneralMath::round(double r) const
{
	return static_cast<int>((r > 0.0) ? std::floor(r + 0.5) : std::ceil(r - 0.5));
}

int GeneralMath::sign( double x ) const
{
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

double GeneralMath::Fabs(double x) const
{
    return std::fabs(x);
}

double GeneralMath::Log2( double n ) const
{
    return log(n) / log(2.0);
}

// https://stackoverflow.com/a/34660211
double GeneralMath::PowInt(double base, int exp) const
{
    if (exp == 0)
    {
        return 1;
    }
    const double temp = PowInt(base, exp/2);       
    const double temp2 = temp*temp;
    if (exp%2 == 0)
        return temp2;
    else {
        if(exp > 0)
            return base*temp2;
        else
            return (temp2)/base; //negative exponent computation 
    }
}

double GeneralMath::LinearInterpol( double x, const Point & p1, const Point & p2 ) const
{
    // y = ax + b
    const Point pDiff = p2 - p1;
    if ( pDiff.x == 0 )
        return p1.y;

    const LineParams & lpar = CalcLineParams(p1, p2);
    const double y = lpar.a * x + lpar.b;
    return y;
}

double GeneralMath::FindIntercept( double y, const Point & p1, const Point & p2 ) const
{
    const Point pDiff = p2 - p1;
    if ( pDiff.x == 0 )
        return p1.y;
    if ( pDiff.y == 0 )
        return p1.x;

    const LineParams & lpar = CalcLineParams(p1, p2);
    const double x = (y - lpar.b) / lpar.a;

    return x;
}

GeneralMath::LineParams GeneralMath::CalcLineParams(const Point & p1, const Point & p2) const
{
    const Point pDiff = p2 - p1;
    LineParams lpar;
    lpar.a = pDiff.y / pDiff.x;
    lpar.b = p1.y - lpar.a * p1.x;
    return lpar;
}

double GeneralMath::GetInPIRange( double angle ) const
{
    while ( angle > PI )  angle -= 2*PI;
    while ( angle < -PI ) angle += 2*PI;

    return angle;
}

double GeneralMath::GetIn2PIRange( double angle ) const
{
    angle = fmod(angle, 2*PI);
    return angle;
}

double GeneralMath::GetIn0_2PIRange( double angle ) const
{
    angle = GetIn2PIRange(angle);
    if (angle < 0) angle += 2*PI;
    return angle;
}

/**
Bound binary seach should finish in log2(n) iterations. Let's allow for max 2 logs.
*/
int GeneralMath::GetMaxIterBinSearchBound(double minArg, double maxArg, double eps) const
{
    const double numSlices = this->round( fabs(maxArg-minArg) / eps);
    int maxIter = 2 * this->round(this->Log2(numSlices));
    return maxIter;
}

EnjoLib::VecD GeneralMath::UniformDistr(int n, double min, double max) const
{
    const double len = (max - min) / double(n + 1);
    EnjoLib::VecD ret;

    for (int i = 0; i < n; ++i)
    {
        const double pos = min + (i+1) * len;
        ret.push_back(pos);
    }
    return ret;
}

int GeneralMath::GetGreatestCommonDivisor(int a, int b) const
{
    //https://pl.wikipedia.org/wiki/Algorytm_Euklidesa
    while(b != 0)             // Tworzymy pętlę działającą gdy b ≠ 0
    {
        int c = a % b;              // Zmienna c przyjmuje wartość a modulo b
        a = b;                // Przypisujemy b do a
        b = c;                // Przypisujemy c do b
    }
    return a;                 // Zwracamy a, czyli żądane NWD(a,b)
}

int GeneralMath::GetNumDigits(double number) const
{
    int digits = 0;
    if (number < 0) digits = 1; // remove this line if '-' counts as a digit
    while (number >= 1) {
        number /= 10;
        digits++;
    }
    return digits;
}

double GeneralMath::RelativeChange(double val, double valRef) const
{
    if (valRef == 0)
        return 0;
    return (val - valRef) / valRef;
}

double GeneralMath::AbsoluteChange(double val, double valRef) const
{
    return val - valRef;
}

double GeneralMath::PointsPower(double x, double power) const
{
    double out = 0;
    if (x >= 0)
        out = -1 + pow(x + 1, power);
    else
        out = -(-1 + pow(-x + 1, power));

    return out;
}

float GeneralMath::PercentDone(double iter, double maxIter) const
{
    if (maxIter == 0)
    {
        return 0;
    }
    const float percDone = Percent(iter / maxIter);
    return percDone;
}

float GeneralMath::Percent(double fraction) const
{
    const float percDone = round(10000 * fraction) / 100.0;
    return percDone;
}

//https://stackoverflow.com/a/12700533
long long unsigned GeneralMath::Concatenate(long long unsigned first, long long unsigned second, int leadingZeroes) const
{
    long long unsigned pow = 10;
    while(second >= pow)
    {
        pow *= 10;
    }
    int numDigi2nd = GetNumDigits(second);
    if (second == 0)
    {
        ++numDigi2nd;
    }
    const int addZeros = leadingZeroes - numDigi2nd + 1;
    for (int i = 0; i < addZeros; ++i)
    {
        pow *= 10;
    }
    return first * pow + second;
}
