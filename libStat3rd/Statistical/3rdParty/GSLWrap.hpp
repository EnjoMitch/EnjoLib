#ifndef GSLWRAP_H
#define GSLWRAP_H

#include <gsl/gsl_multifit.h>

namespace EnjoLib {
    
class VecD;

struct GSL_WrapperVector
{
    gsl_vector * vec = nullptr;

    GSL_WrapperVector(int sz);
    GSL_WrapperVector(const EnjoLib::VecD & inp);

    ~GSL_WrapperVector();
};
struct GSL_WrapperMatrix
{
    gsl_matrix * mat = nullptr;

    GSL_WrapperMatrix(int szx, int szy);
    ~GSL_WrapperMatrix();
};

struct GSL_Wrapper_multifit_linear_workspace
{
    gsl_multifit_linear_workspace *ws = nullptr;
    GSL_Wrapper_multifit_linear_workspace(int obsNum, int degree);
    ~GSL_Wrapper_multifit_linear_workspace();
};

class GSLWrap
{
    public:
        GSLWrap();
        virtual ~GSLWrap();

    protected:

    private:
};

}

#endif // GSLWRAP_H
