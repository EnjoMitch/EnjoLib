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

#include "EigenNewmat10.hpp"

#include "../Matrix.hpp"
#include "../../Util/VecD.hpp"
#include <STD/VectorCpp.hpp>

//#ifdef use_namespace
//using namespace RBD_LIBRARIES;
//#endif
//#define use_namespace
//#define WANT_STREAM            // include iostream and iomanipulators

//#define use_namespace
#include <newmat10/newmatap.h>          // newmat headers including advanced functions
#include <newmat10/newmatio.h>          // newmat headers including output functions

//using namespace RBD_LIBRARIES;

using namespace std;
//using namespace EnjoLib;


#include <Util/CoutBuf.hpp>

EnjoLib::EigenNewmat10::EigenNewmat10(){}
EnjoLib::EigenNewmat10::~EigenNewmat10(){}

/*
string getDiag( const DiagonalMatrix & D )
{
    Osstream ss;
    ss << setw(17) << setprecision(14);
    for ( int i = 1; i <= D.Nrows(); ++i ) for ( int j = 1; j <= D.Ncols(); ++j )
            if ( i == j )
                ss << D(i, j) << endl;
    return ss.str();
}
*/

static SymmetricMatrix ConvertMatrix( const EnjoLib::Matrix & m )
{
    int n = m.GetNCols();
    SymmetricMatrix H(n);
    for ( int i = 1; i <= n; ++i ) for ( int j = 1; j <= n; ++j )
            H(i, j) = m.at(i-1).at(j-1);

    return H;
}

static std::vector<EnjoLib::EigenValueVector> StatGetEigenValVec( const EnjoLib::Matrix & m )
{
    std::vector<EnjoLib::EigenValueVector> ret;
    Tracer tr("GetEigenValVecClient");      // for tracking exceptions

    SymmetricMatrix H = ConvertMatrix(m);

    Matrix U;
    DiagonalMatrix D;
    EigenValues(H, D, U);

    for ( int j = 1; j <= m.GetNCols(); ++j )
    {
        EnjoLib::VecD eigenVector;
        double eigenValue = 0;
        for ( int i = 1; i <= m.GetNCols(); ++i )
        {
             if ( i == j )
                eigenValue  = D(i, j);

            eigenVector.push_back(U(i, j));

        }
        ret.push_back( EnjoLib::EigenValueVector(eigenValue, eigenVector ) );
    }
    return ret;
}


std::vector<EnjoLib::EigenValueVector> EnjoLib::EigenNewmat10::GetEigenValVecClient( const EnjoLib::Matrix & m ) const
{
    return StatGetEigenValVec(m);
}
