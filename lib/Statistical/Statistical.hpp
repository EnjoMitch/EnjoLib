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

#ifndef STATISTICAL_H
#define STATISTICAL_H

#include "../3rdParty/stdfwd.hh"
#include "../Util/VecD.hpp"

namespace EnjoLib
{
class VecD;
class Matrix;
class ScalingOpStandardize;
class ScalingOpStandardizeInvert;

class Statistical
{
    public:
        Statistical();
        virtual ~Statistical();

        double METwo(const VecD & v1, const VecD & v2) const;
        double ME(const VecD & v) const;
        double RMSTwo(const VecD & v1, const VecD & v2) const;
        double RMS(const VecD & v) const;
        double CohendEffectSize(const VecD & v1, const VecD & v2) const;
        double StandardDeviation( const VecD & v ) const;
        double StandardDeviation( const Matrix & m ) const;
        double DistFromMean( const Matrix & m, const VecD & v ) const;
        double Median( const VecD & v ) const;
        double Variance( const VecD & v ) const;
        double Covariance( const VecD & v1, const VecD & v2 ) const;
        double SumMulDiffMean( const VecD & v1, const VecD & v2 ) const;

        double SpreadMinMax( const VecD & v ) const;
        double SpreadMinMax2Avg( const VecD & v ) const;

        VecD RemoveLeadingZeroes( const VecD & v ) const;

        VecD StandardizeInvert( const ScalingOpStandardizeInvert & scaleOp, const VecD & applyVec ) const;
        VecD Standardize( const ScalingOpStandardize & scaleOp, const VecD & applyVec ) const;
        Matrix  Standardize( const stdfwd::vector<ScalingOpStandardize> & scalersOp, const Matrix & applyMat ) const;
        VecD Standardize( const VecD & refVec, const VecD & applyVec ) const;
        VecD Standardize( const VecD & refVec ) const;
        Matrix  Standardize( const Matrix & refMat, const Matrix & applyMat ) const;
        Matrix  Standardize( const Matrix & refMat ) const;
        VecD MeanCols( const Matrix & v ) const;
        VecD RelativeChange( const VecD & v ) const;
        VecD AbsoluteChange( const VecD & v ) const;
        Matrix CovarianceMatrix( const Matrix & data ) const;
    protected:
    private:
        VecD Change( const VecD & v, bool relative ) const;
        VecD PrepareDiff(const VecD & v1, const VecD & v2) const;
};
}
#endif // STATISTICAL_H
