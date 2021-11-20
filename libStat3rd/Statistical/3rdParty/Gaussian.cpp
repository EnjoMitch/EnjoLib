#include "Gaussian.hpp"
#include "GSLWrap.hpp"
#include <Util/VecD.hpp>

using namespace EnjoLib;

extern "C"
{
#include <gsl/gsl_math.h>
#include <gsl/gsl_filter.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
}
Gaussian::Gaussian()
{
    //ctor
}

Gaussian::~Gaussian()
{
    //dtor
}

struct GSL_Wrapper_gsl_filter_gaussian_workspace
{
    gsl_filter_gaussian_workspace * gauss_p = nullptr;
    GSL_Wrapper_gsl_filter_gaussian_workspace(int windowSizeK)
    {
        gauss_p = gsl_filter_gaussian_alloc(windowSizeK);
    }
    ~GSL_Wrapper_gsl_filter_gaussian_workspace()
    {
        gsl_filter_gaussian_free(gauss_p);
    }
};

VecD Gaussian::fit(double alpha, int predictAhead, const VecD & dy) const
{
    VecD ret;
    const size_t N = dy.size();                        /* length of time series */
    const size_t K = N/4;                         /* window size */
    GSL_WrapperVector x(dy);         /* input vector */
    GSL_WrapperVector y1(N);        /* filtered output vector for alpha1 */

    GSL_Wrapper_gsl_filter_gaussian_workspace gauss_p(K);
    /* apply filters */
    gsl_filter_gaussian(GSL_FILTER_END_PADVALUE, alpha, 0, x.vec, y1.vec, gauss_p.gauss_p);

    /* print filter results */
    for (size_t i = 0; i < N; ++i)
    {
        double y1i = gsl_vector_get(y1.vec, i);
        ret.push_back(y1i);
    }
    return ret;
}
