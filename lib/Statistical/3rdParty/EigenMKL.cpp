#include "EigenMKL.hpp"
#include "EigenEigen3.hpp"
#include "../Matrix.hpp"
#include "../../Template/CorradePointer.h"
#include <STD/VectorCpp.hpp>

using namespace EnjoLib;

EigenMKL::EigenMKL(){}
EigenMKL::~EigenMKL(){}

//#define USE_EIGEN_MKL

#ifdef USE_EIGEN_MKL
#include "mkl_lapacke.h"
static Corrade::Containers::Pointer<MKL_Complex16> ConvertMatrix( const Matrix & m )
{
    MKL_Complex16 * mat = new MKL_Complex16[m.GetNRows() * m.GetNCols()];
    for ( int i = 0; i < m.GetNRows(); ++i ) for ( int j = 0; j < m.GetNCols(); ++j )
        mat[i * m.GetNRows() + j] = MKL_Complex16 {m.at(i).at(j), 0};

    return Corrade::Containers::Pointer<MKL_Complex16>(mat);
}
#endif

std::vector<EigenValueVector> EigenMKL::GetEigenValVecClient( const Matrix & m ) const
{
#ifndef USE_EIGEN_MKL
    return EigenEigen3().GetEigenValVecClient(m);
#else
    std::vector<EigenValueVector> ret;
    ret.reserve(m.GetNRows());

    const Corrade::Containers::Pointer<MKL_Complex16> & matE = ConvertMatrix(m);
    MKL_INT n = m.GetNCols(), lda = m.GetNRows(), info;
    //MKL_INT n = m.GetNRows(), lda = m.GetNCols(), info;
    Corrade::Containers::Pointer<double> w(new double[m.GetNCols()]);

    info = LAPACKE_zheevd( LAPACK_COL_MAJOR, 'V', 'L', n, matE.get(), lda, w.get() );
    /* Check for convergence */
    if( info > 0 ) {
            printf( "The algorithm failed to compute eigenvalues.\n" );
            exit( 1 );
    }


    //const auto & eval  = es.eigenvalues();
    //const auto & evect = es.eigenvectors();
    const double * wdata = w.get();
    const MKL_Complex16 * evectors = matE.get();
    for ( int i = 0; i < m.GetNRows(); ++i )
    {
        const double eigenValue = wdata[i];
        VectorD eigenVector;
        eigenVector.reserve(m.GetNCols());

        for ( int j = 0; j < m.GetNCols(); ++j )
        {
            //const double val = evect(j, i).real(); // Transposition (j, i) due to internal Eigen storage!
            const double val = -evectors[i * m.GetNRows() + j].real;
            eigenVector.push_back(val);
        }

        ret.push_back( EigenValueVector(eigenValue, eigenVector) );
    }
    return ret;
#endif

}

