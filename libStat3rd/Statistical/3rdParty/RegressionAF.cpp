#include "RegressionAF.hpp"
//#include "RegressionGSL.h"

//#include <Util/VecF.hpp>
#include <Util/VecD.hpp>
#include <Template/CorradePointer.h>
#include "RegressionFactory.hpp"

#ifdef WITH_FEATURE_ARRAY_FIRE
    #include <arrayfire.h>
#endif


using namespace std;
using namespace EnjoLib;

RegressionAF::RegressionAF(){}
RegressionAF::~RegressionAF(){}

VecD RegressionAF::polynomialfit(int degree, const VecD & dxx, const VecD & dyy) const
{
#ifndef WITH_FEATURE_ARRAY_FIRE    
    return RegressionFactory().CreateDefault()->polynomialfit(degree, dxx, dyy);
#else
    const int obs = dxx.size();
    VecD data;
    
    //for(int i=0; i < obs; i++)
    {
        for(int j=0; j < degree; j++)
        {
            for(int i=0; i < obs; i++)
            {
                //gsl_matrix_set(X.mat, i, j, pow(dx[i], j));
                //A(i, j) = pow(dx[i], j);
                //A(i, j) = dx[i];
                data.push_back(pow(dxx[i], j));
            }
        }
    }
    af::array AAA(obs, degree, data.data());
    
    //af_print(AAA);

    //const MatrixXd & aTrans = A.transpose();
	//const auto & f = (aTrans*A).inverse()*aTrans*b;

	af::array B00(dyy.size(), dyy.data());
	//af_print(B00);

    af::array X1 = af::matmul(af::inverse(af::matmul(af::transpose(AAA), AAA)), (af::matmul(af::transpose(AAA), B00)));
    
    //cout << "X1 \n";
    //af_print(X1);
    
    VecD coeD(degree);
    X1.host(coeD.data());
    return coeD;
#endif
} 
