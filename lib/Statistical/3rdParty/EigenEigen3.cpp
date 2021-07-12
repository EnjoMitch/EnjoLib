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

#include "EigenEigen3.hpp"
#include "../Matrix.hpp"
#include "../../Util/VecD.hpp"
#include <Util/Except.hpp>
#include <Util/CharManipulations.hpp>

#include <STD/VectorCpp.hpp>

//#define EIGEN_USE_MKL_ALL
//#define EIGEN_USE_BLAS // Enables openblas64 - somewhat slower
//#define EIGEN_USE_LAPACKE // Don't use currently
#include <Eigen/Dense>

#include <Util/CoutBuf.hpp>

using namespace std;
using namespace EnjoLib;
//using namespace Eigen;

EigenEigen3::~EigenEigen3(){} 
EigenEigen3::EigenEigen3(){}

static Eigen::MatrixXd ConvertMatrix( const Matrix & m )
{
    const int nrows = m.GetNRows();
    const int ncols = m.GetNCols();
    Eigen::MatrixXd mateig(nrows, ncols);
    for ( int i = 0; i < nrows; ++i ) for ( int j = 0; j < ncols; ++j )
            mateig(i, j) = m.at(i).at(j);

    return mateig;
}

std::vector<EigenValueVector> EigenEigen3::GetEigenValVecClient( const Matrix & m ) const
{
    std::vector<EigenValueVector> ret;
    ret.reserve(m.GetNRows());
    
    //cout << "M = " << m.GetNCols() << ", " << m.GetNRows() << endl;

    Eigen::EigenSolver<Eigen::MatrixXd> es;
    const Eigen::MatrixXd & matE = ConvertMatrix(m);
    //cout << "Pre\n" << m.Print() << endl;
    es.compute(matE, /* computeEigenvectors = */ true);
    //cout << "Post" << endl;
    if (es.info() != Eigen::ComputationInfo::Success)
    {
        ELO
        LOG << "Eigenvalue Calculation not successful: " << es.info() << NL3;
        //cout << m.Print() << endl;
        throw EnjoLib::ExceptRuntimeError("Eigenvalue Calculation not successful " + CharManipulations().ToStr(es.info()));
        LOG << "After throw: " << es.info() << NL3;
    }

    const auto & eval  = es.eigenvalues();
    const auto & evect = es.eigenvectors();
    for ( int i = 0; i < m.GetNRows(); ++i )
    {
        const auto & evali = eval(i);
        const double eigenValue = evali.real();
        VecD eigenVector;
        eigenVector.reserve(m.GetNCols());

        for ( int j = 0; j < m.GetNCols(); ++j )
        {
            const double val = evect(j, i).real(); // Transposition (j, i) due to internal Eigen storage!
            eigenVector.push_back(val);
        }

        ret.push_back( EigenValueVector(eigenValue, eigenVector) );
    }
    return ret;
}
