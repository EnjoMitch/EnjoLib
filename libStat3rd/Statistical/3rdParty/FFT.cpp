#include "FFT.hpp"
#include "GSLWrap.hpp"
#include <Util/VecD.hpp>
#include <STD/VectorCpp.hpp>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_fft_real.h>
#include <gsl/gsl_fft_halfcomplex.h>

using namespace EnjoLib;

FFT::FFT() {}
FFT::~FFT() {}

struct GSL_Wrapper_fft_real_wavetable
{
    gsl_fft_real_wavetable * real = nullptr;

    GSL_Wrapper_fft_real_wavetable(int sz)
    {
        real = gsl_fft_real_wavetable_alloc(sz);
    }
    ~GSL_Wrapper_fft_real_wavetable()
    {
        gsl_fft_real_wavetable_free (real);
    }
};

struct GSL_Wrapper_gsl_fft_real_workspace
{
    gsl_fft_real_workspace * work = nullptr;

    GSL_Wrapper_gsl_fft_real_workspace(int sz)
    {
        work = gsl_fft_real_workspace_alloc(sz);
    }
    ~GSL_Wrapper_gsl_fft_real_workspace()
    {
        gsl_fft_real_workspace_free(work);
    }
};

struct GSL_Wrapper_gsl_halfcomplex_wavetable
{
    gsl_fft_halfcomplex_wavetable * hc = nullptr;

    GSL_Wrapper_gsl_halfcomplex_wavetable(int sz)
    {
        hc = gsl_fft_halfcomplex_wavetable_alloc(sz);
    }
    ~GSL_Wrapper_gsl_halfcomplex_wavetable()
    {
        gsl_fft_halfcomplex_wavetable_free(hc);
    }
};

VecD FFT::fit(int harmonics, int predictAhead, const VecD & dy) const
{
    std::vector<double> data = dy.ToVecDouble();
    {
        int n = data.size();
        GSL_Wrapper_gsl_fft_real_workspace work(n);
        GSL_Wrapper_fft_real_wavetable real(n);
        gsl_fft_real_transform (data.data(), 1, n, real.real, work.work);
    }
    {
        for (int i = 0; i < predictAhead; ++i)
        {
            //data.push_back(0);
        }
        int n = data.size();
        for (int i = harmonics * 2; i < n; i++)
        {
            data[i] = 0;
        }
        GSL_Wrapper_gsl_fft_real_workspace work(n);
        GSL_Wrapper_gsl_halfcomplex_wavetable hc(n);
        gsl_fft_halfcomplex_inverse (data.data(), 1, n, hc.hc, work.work);
        VecD ret = data;
        return ret;
    }
}
