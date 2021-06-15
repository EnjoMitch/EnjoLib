/*
Modified BSD License

This file is a part of Statistical package and originates from:
http://sf.net/projects/enjomitchsorbit

Copyright (c) 2012, Szymon "Enjo" Ender
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

#include "Statistical.hpp"
#include "Assertions.hpp"
//#include "VecD.hpp"
#include "Matrix.hpp"
#include "ScalingOpStandardize.hpp"
#include "ScalingOpStandardizeInvert.hpp"

#include "../Math/GeneralMath.hpp"

#include <STD/VectorCpp.hpp>
//#include <cstdlib>
#include <cmath>
#include <STD/Algorithm.hpp>
//#include <Util/CoutBuf.hpp>

using namespace std;
using namespace EnjoLib;


Statistical::Statistical(){}
Statistical::~Statistical(){}

double Statistical::SumMulDiffMean( const VecD & v1, const VecD & v2 ) const
{
    Assertions::SizesEqual(v1, v2, "Statistical::SumSquares");
    const double mean1 = v1.Mean();
    const double mean2 = v2.Mean();

    double sumSquares = 0;
    for ( size_t i = 0; i < v1.size(); ++i )
    {
        const double diff1 = v1[i] - mean1;
        const double diff2 = v2[i] - mean2;
        sumSquares += diff1 * diff2;
    }
    /*
    if (sumSquares == 0)
    {
        cout << v1.PrintPython("V1") << endl;
        cout << v1.PrintPython("V2")<< endl;
        int a = 1;
        int b = a;
    }
    */
    return sumSquares;
}

double Statistical::StandardDeviation( const VecD & v ) const
{
    Assertions::AtLeast2Dimensions(v,"Statistical::StandardDeviation");
    const double variance = Variance(v);
    const double sd = sqrt(variance);
    return sd;
}

double Statistical::StandardDeviation( const Matrix & m ) const
{
    double sumVariances = 0;
    const Matrix & mT = m.T();
    for (size_t i = 0; i < mT.size(); ++i)
    {
        const double variance = Variance(mT.at(i));
        sumVariances += variance;
    }
    const double sd = sqrt(sumVariances);
    return sd;
}

double Statistical::DistFromMean( const Matrix & m, const VecD & v ) const
{
    //Assertions::AtLeast2Dimensions(m,"Statistical::DistFromMean");
    const Matrix & mT = m.T();
    double sumVariances = 0;
    for (size_t i = 0; i < mT.size(); ++i)
    {
        const double mean = mT.at(i).Mean();
        const double diff = v.at(i) - mean;
        const double diffSquare = diff * diff;
        const double n = mT.at(i).size() - 1;
        sumVariances += diffSquare / n;
    }
    const double sd = sqrt(sumVariances);
    return sd;
}

double Statistical::Variance( const VecD & v ) const
{
    Assertions::AtLeast2Dimensions(v,"Statistical::Variance");
    double diffMean = SumMulDiffMean(v, v);
    double sizeMinus1 = v.size() - 1;
    Assertions::IsNonZero(sizeMinus1,"Statistical::Variance");
    double var = diffMean / sizeMinus1;

    return var;
}

double Statistical::Covariance( const VecD & v1, const VecD & v2 ) const
{
    Assertions::SizesEqual(v1, v2, "Statistical::Covariance");
    Assertions::AtLeast2Dimensions(v1,"Statistical::Covariance");

    double diffMean = SumMulDiffMean(v1, v2);
    double sizeMinus1 = v1.size() - 1;
    double covar = diffMean / sizeMinus1;

    return covar;
}

Matrix Statistical::CovarianceMatrix( const Matrix & data ) const
{
    unsigned dimensions = data.GetNCols();
    Matrix covMat(dimensions);
    const Matrix & dataT = data.T();
    for (unsigned i = 0; i < dimensions; ++i)
    {
        const VecD & vi = dataT.at(i);
        for (unsigned j = i; j < dimensions; ++j)
        {
            const VecD & vj = dataT.at(j);
            double cov = Covariance(vi, vj);

            covMat.atw(i).atw(j) = cov;
            covMat.atw(j).atw(i) = cov;
        }
    }
    return covMat;
}

double Statistical::Median( const VecD & v ) const
{
    Assertions::NonEmpty(v, "Statistical::Median");
    VecD sorted(v.size());
    std::partial_sort_copy (v.Data().begin(), v.Data().end(), sorted.DataRW().begin(), sorted.DataRW().end());
    double median = sorted.at(sorted.size() / 2);
    return median;
}

VecD Statistical::StandardizeInvert( const ScalingOpStandardizeInvert & scaleOp, const VecD & applyVec ) const
{
    Assertions::NonEmpty(applyVec, "Statistical::StandardizeInvert - applyVec");
    VecD ret; ret.reserve(applyVec.size());
    std::transform(applyVec.begin(), applyVec.end(), std::back_inserter(ret), scaleOp);
    return ret;
}

VecD Statistical::Standardize( const ScalingOpStandardize & scaleOp, const VecD & applyVec ) const
{
    Assertions::NonEmpty(applyVec, "Statistical::Standardize - applyVec");
    VecD ret; ret.reserve(applyVec.size());
    std::transform(applyVec.begin(), applyVec.end(), std::back_inserter(ret), scaleOp);
    return ret;
}
Matrix Statistical::Standardize( const std::vector<ScalingOpStandardize> & scalersOp, const Matrix & applyMat ) const
{
    Assertions::NonEmpty(applyMat, "Statistical::Standardize - applyMat");
    Assertions::SizesEqual( scalersOp.size(), applyMat.GetNCols(), "Statistical::Standardize - applyMat");

    Matrix ret = applyMat;
    for (int ifeat = 0; ifeat < int(scalersOp.size()); ++ifeat)
    {
        const ScalingOpStandardize & scalerOp = scalersOp.at(ifeat);
        //cout << "scalex = " << scalerx.ToStr() << endl;
        for (VecD & row : ret)
        {
            row.atw(ifeat) = scalerOp(row.at(ifeat));
        }
    }
    return ret;
}

VecD Statistical::Standardize( const VecD & refVec, const VecD & applyVec ) const
{
    const ScalingOpStandardize scaleOp(refVec);
    return Standardize(scaleOp, applyVec);
}

VecD Statistical::Standardize( const VecD & refVec ) const
{
    return Standardize(refVec, refVec);
}

Matrix Statistical::Standardize( const Matrix & refMat, const Matrix & applyMat ) const
{
    Assertions::NonEmpty(refMat, "Statistical::Standardize Mat ref");
    Assertions::NonEmpty(applyMat, "Statistical::Standardize Mat apply");
    Assertions::SizesEqual(refMat.at(0), applyMat.at(0), "Statistical::Standardize");

    const Matrix & matT = refMat.T();
    const Matrix & matApplyT = applyMat.T();
    Matrix standardizedT;
    for (int i = 0; i < int(matT.size()); ++i)
    {
        const VecD & stdVec = Standardize(matT.at(i), matApplyT.at(i));
        standardizedT.push_back(stdVec);
    }
    return standardizedT.T();
}

Matrix Statistical::Standardize( const Matrix & refMat ) const
{
    return Standardize(refMat, refMat);
}

double Statistical::RMS( const VecD & v) const
{
    Assertions::NonEmpty(v, "Statistical::RMS");
    double sumSquared = 0;
    for (unsigned i = 0; i < v.size(); ++i)
    {
        const double val = v.at(i);
        const double val2 = val*val;
        sumSquared += val2;
    }
    const double divided = sumSquared / double(v.size());
    const double squareroot = sqrt(divided);
    return squareroot;
}

double Statistical::RMSTwo(const VecD & v1, const VecD & v2) const
{
    Assertions::NonEmpty(v1, "Statistical::RMSTwo");
    Assertions::SizesEqual(v1, v2, "Statistical::RMSTwo");
    return RMS(PrepareDiff(v1, v2));
}

VecD Statistical::PrepareDiff(const VecD & v1, const VecD & v2) const
{
    Assertions::NonEmpty(v1, "Statistical::PrepareDiff");
    Assertions::SizesEqual(v1, v2, "Statistical::PrepareDiff");
    VecD diff(v1.size());
    for (unsigned i = 0; i < v1.size(); ++i)
    {
        const double dif = v1[i] - v2[i];
        diff[i] = dif;
    }
    return diff;
}

VecD Statistical::RemoveLeadingZeroes( const VecD & vec ) const
{
    VecD ret;
    bool firstNonZero = false;
    for (unsigned i = 0; i < vec.size(); ++i)
    {
        const double val = vec.at(i);
        if (val == 0 && ! firstNonZero)
        {
            continue;
        }
        else
        {
            firstNonZero = true;
        }
        if (firstNonZero)
        {
            ret.Add(val);
        }
    }
    return ret;
}

double Statistical::METwo(const VecD & v1, const VecD & v2) const
{
    Assertions::NonEmpty(v1, "Statistical::METwo");
    Assertions::SizesEqual(v1, v2, "Statistical::METwo");
    return ME(PrepareDiff(v1, v2));
}

double Statistical::ME(const VecD & v) const
{
    Assertions::NonEmpty(v, "Statistical::ME");
    const double ret = v.SumAbs() / double(v.size());
    return ret;
}

/// Calculates distance between means in terms of standard deviations' distance
double Statistical::CohendEffectSize(const VecD & v1, const VecD & v2) const
{
    const char * idd = "Statistical::CohendEffectSize";
    Assertions::AtLeast2Dimensions(v1, idd);
    Assertions::AtLeast2Dimensions(v2, idd);
    const double var1 = Variance(v1);
    const double var2 = Variance(v2);
    const double sz1 = v1.size();
    const double sz2 = v2.size();
    const double mn1 = v1.Mean();
    const double mn2 = v2.Mean();

    const double pooledStdDev = sqrt(((sz1 - 1) * var1 + (sz2 - 1) * var2) / (sz1 + sz2 - 2));
    Assertions::IsNonZero(pooledStdDev, idd);
    const double effectSize = (mn1 - mn2) / pooledStdDev;
    return effectSize;
}

VecD Statistical::RelativeChange( const VecD & v ) const
{
    return Change(v, true);
}

VecD Statistical::AbsoluteChange( const VecD & v ) const
{
    return Change(v, false);
}

VecD Statistical::Change( const VecD & v, bool relative ) const
{
    VecD ret;
    GeneralMath gmh;
    for (int i = 1; i < int(v.size()); ++i)
    {
        const double vCurr = v.at(i);
        const double vPrev = v.at(i-1);
        const double chng = relative ? gmh.RelativeChange(vCurr, vPrev) : gmh.AbsoluteChange(vCurr, vPrev);
        ret.push_back(chng);
    }
    return ret;
}

VecD Statistical::MeanCols( const Matrix & m ) const
{
    VecD ret;
    const Matrix & t = m.T();
    for (size_t i = 0; i < t.size(); ++i)
    {
        ret.push_back(t.at(i).Mean());
    }
    return ret;
}

double Statistical::SpreadMinMax( const VecD & vvv ) const
{
    const char * idd = "Statistical::SpreadMinMax";
    Assertions::AtLeast2Dimensions(vvv, idd);
    const double maxx = vvv.Max();
    const double minn = vvv.Min();
    if (maxx * minn < 0)
    {
        // Both have different signs
        const double diff = maxx - minn;
        return diff;
    }
    else
    {
        VecD both;
        both.Add(maxx);
        both.Add(minn);
        const double maxxxx = both.MaxAbs();
        return maxxxx;
    }
}

double Statistical::SpreadMinMax2Avg( const VecD & vvv ) const
{
    const char * idd = "Statistical::SpreadMinMax2Avg";
    Assertions::AtLeast2Dimensions(vvv, idd);
    const double diff = SpreadMinMax(vvv);
    const double avg = vvv.Mean();
    Assertions::IsNonZero(avg, idd);

    const double spread = diff / avg;
    //const double spread = fabs(maxx / minn - 1);
    //const double spread = GeneralMath().RelativeChange(maxx, minn);

    return spread;
}

