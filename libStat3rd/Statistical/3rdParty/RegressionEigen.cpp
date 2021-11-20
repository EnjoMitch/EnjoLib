#include "RegressionEigen.hpp"
#include "RegressionGSL.hpp"
#include <Math/GeneralMath.hpp>
#include <Util/VecD.hpp>

//#define EIGEN_USE_MKL_ALL
//#define EIGEN_USE_BLAS // Enables openblas64
#include <Eigen/Dense>

 
using namespace std; 
using namespace Eigen;
using namespace EnjoLib;

RegressionEigen::RegressionEigen(){}
RegressionEigen::~RegressionEigen(){}

/*
VecD RegressionEigen::polynomialfit(int degree, const VecD & dx, const VecD & dy) const
{
    return RegressionGSL().polynomialfit(degree, dx, dy);
}
*/

VecD RegressionEigen::polynomialfit(int degree, const VecD & dx, const VecD & dy) const
{
    VecD coeffs(degree);
    const int obs = dx.size();
    //VecD weights(obs);
    MatrixXd A(obs, degree);
   //cout << "Here is the matrix A:\n" << A << endl;
    VectorXd b(obs);
    //Map<VectorXd> b(dy.data(), obs, 1);
    //VecD dycopy = dy;
    //Map<VectorXd> b(dycopy.data(), obs);
   const GeneralMath gmat;

    for(int i=0; i < obs; ++i)
    {
        b(i) = dy[i];
        
        //gsl_vector_set(y.vec, i, dy[i]);
        //gsl_vector_set(w.vec, i, weights[i]);
        //gsl_vector_set(w.vec, i, i);        // More weight to latest
        //gsl_vector_set(w.vec, i, obs - i);  // More weight to initial
        //gsl_vector_set(w.vec, i, 1);      // Disabled different weights
        for(int j=0; j < degree; ++j)
        {
            //gsl_matrix_set(X.mat, i, j, pow(dx[i], j));
            A(i, j) = gmat.PowInt(dx[i], j);
            //A(i, j) = dx[i];
        }
    }
    
    /*
    const auto & eigRes = A.bdcSvd(ComputeThinU | ComputeThinV).solve(b);
       cout << "The least-squares solution is:\n"
        << eigRes << endl;
      */  
    //const MatrixXd & aTrans = A.transpose();
	//const auto & f = (aTrans*A).inverse()*aTrans*b;
	const auto & f = (A.transpose()*A).inverse()*A.transpose()*b; // Faster
	
	// Faster!
	//const auto & f = (A.transpose()*A).inverse()*A.transpose()*b;
	//const auto & ff = A.colPivHouseholderQr().solve(b);
	//const auto & ff = A.bdcSvd(ComputeThinU | ComputeThinV).solve(b);
	
	//cout << "Matrix f" << endl;
	//cout << ff << endl;

    /* store result ... */
    for(int i=0; i < degree; ++i)
    {
        const double coeff = f(i, 0);
        //cout << "Coeff " << i << " = " << coeff << endl;;
        coeffs[i] = coeff;
    }
    return coeffs; /* we do not "analyse" the result (cov matrix mainly)
          to know if the fit is "good" */
    // http://stats.stackexchange.com/questions/151018/how-does-the-covariance-matrix-of-a-fit-get-computed
}