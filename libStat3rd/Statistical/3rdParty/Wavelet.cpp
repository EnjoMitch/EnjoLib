#include "Wavelet.hpp"

#include <Util/VecD.hpp>
#include <STD/VectorCpp.hpp>
#include <gsl/gsl_sort.h>
#include <gsl/gsl_wavelet.h>

#include <Math/GeneralMath.hpp>

using namespace EnjoLib;

Wavelet::Wavelet(){}
Wavelet::~Wavelet(){}

VecD Wavelet::fit(int harmonics, int predictAhead, const VecD & dy) const
{
    std::vector<double> data = dy.ToVecDouble();
    
    int i, n = dy.size(), nc = 20;
    std::vector<double> abscoeff(n);
    size_t *p = new size_t(n);

  gsl_wavelet *w;
  gsl_wavelet_workspace *work;

  w = gsl_wavelet_alloc (gsl_wavelet_daubechies, 4);
  work = gsl_wavelet_workspace_alloc (n);

  gsl_wavelet_transform_forward (w, data.data(), 1, n, work);

  for (i = 0; i < n; i++)
    {
      abscoeff[i] = GeneralMath().Fabs(data.data()[i]);
    }

  gsl_sort_index (p, abscoeff.data(), 1, n);

  for (i = 0; (i + nc) < n; i++)
    data[p[i]] = 0;

  gsl_wavelet_transform_inverse (w, data.data(), 1, n, work);


  gsl_wavelet_free (w);
  gsl_wavelet_workspace_free (work);

  return data;
}
