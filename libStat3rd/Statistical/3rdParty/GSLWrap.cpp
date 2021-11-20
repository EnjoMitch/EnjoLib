#include "GSLWrap.hpp"
#include <Util/VecD.hpp>
#include <gsl/gsl_multifit.h>

using namespace EnjoLib;

GSLWrap::GSLWrap()
{
}

GSLWrap::~GSLWrap()
{
}

GSL_WrapperVector::GSL_WrapperVector(int sz)
{
    vec = gsl_vector_alloc(sz);
}
GSL_WrapperVector::GSL_WrapperVector(const EnjoLib::VecD & inp)
: GSL_WrapperVector(inp.size())
{
    for (size_t i = 0; i < inp.size(); ++i)
    {
        gsl_vector_set(vec, i, inp.at(i));
    }
}
GSL_WrapperVector::~GSL_WrapperVector()
{
    gsl_vector_free(vec);
}

GSL_WrapperMatrix::GSL_WrapperMatrix(int szx, int szy)
{
    mat = gsl_matrix_alloc(szx, szy);
}
GSL_WrapperMatrix::~GSL_WrapperMatrix()
{
    gsl_matrix_free(mat);
}

GSL_Wrapper_multifit_linear_workspace::GSL_Wrapper_multifit_linear_workspace(int obsNum, int degree)
{
    ws = gsl_multifit_linear_alloc(obsNum, degree);
}
GSL_Wrapper_multifit_linear_workspace::~GSL_Wrapper_multifit_linear_workspace()
{
    gsl_multifit_linear_free(ws);
}
