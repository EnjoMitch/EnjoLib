#include "RegressionGSL.hpp"
#include "GSLWrap.hpp"
#include <Util/VecD.hpp>

using namespace EnjoLib;

RegressionGSL::RegressionGSL(){}
RegressionGSL::~RegressionGSL(){}

VecD RegressionGSL::polynomialfit(int degree, const VecD & dx, const VecD & dy) const
{
    VecD coeffs(degree);
    const int obs = dx.size();
    //VecD weights(obs);
    //gsl_multifit_linear_workspace *ws;
    double chisq;
    GSL_WrapperVector y(obs);
    GSL_WrapperVector x(obs);
    GSL_WrapperVector w(obs);
    GSL_WrapperVector c(degree);
    GSL_WrapperMatrix X(obs, degree);
    GSL_WrapperMatrix cov(degree, degree);

    for(int i=0; i < obs; i++)
    {
        gsl_vector_set(y.vec, i, dy[i]);
        //gsl_vector_set(w.vec, i, weights[i]);
        //gsl_vector_set(w.vec, i, i);        // More weight to latest
        //gsl_vector_set(w.vec, i, obs - i);  // More weight to initial
        gsl_vector_set(w.vec, i, 1);      // Disabled different weights
        for(int j=0; j < degree; j++)
        {
            gsl_matrix_set(X.mat, i, j, pow(dx[i], j));
        }
    }

    GSL_Wrapper_multifit_linear_workspace ws(obs, degree);
    //gsl_multifit_linear(X, y, c, cov, &chisq, ws);
    gsl_multifit_wlinear(X.mat, w.vec, y.vec, c.vec, cov.mat, &chisq, ws.ws);

    /* store result ... */
    for(int i=0; i < degree; i++)
    {
        coeffs.atw(i) = gsl_vector_get(c.vec, i);
    }
    return coeffs; /* we do not "analyse" the result (cov matrix mainly)
          to know if the fit is "good" */
    // http://stats.stackexchange.com/questions/151018/how-does-the-covariance-matrix-of-a-fit-get-computed
}