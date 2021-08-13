#include "LossFunctions.hpp"
#include "Statistical.hpp"
#include <Template/AlgoSTDThin.hpp>

#include <Math/GeneralMath.hpp>
#include <Util/CoutBuf.hpp>

using namespace std;
using namespace EnjoLib;

LossFunctions::LossFunctions(){}
LossFunctions::~LossFunctions(){}

double LossFunctions::GetMAE(const VecD & diffs) const
{
    return Statistical().ME(diffs);
}

double LossFunctions::GetRMS(const VecD & diffs) const
{
    return Statistical().RMS(diffs);
}

double LossFunctions::GetHuber(const VecD & diffs, const double delta) const
{
    const GeneralMath gmat;
    // loss = np.where(np.abs(true-pred) < delta , 0.5*((true-pred)**2), delta*np.abs(true - pred) - 0.5*(delta**2))
    // return np.sum(loss)
    double sum = 0;
    for (const double dif : diffs)
    {
        const double absDif = gmat.Fabs(dif);
        if (absDif < delta)
        {
            const double err = 0.5 * dif * dif;
            sum += err;
        }
        else
        {
            const double err = delta * absDif - 0.5 * (delta * delta);
            sum += err;
        }
    }
    return sum;
}

double LossFunctions::GetLogCosh(const VecD & diffs) const
{
    const GeneralMath gmat;
    // loss = np.log(np.cosh(pred - true))
    // return np.sum(loss)
    VecD errors;

    for (const double dif : diffs)
    {
        const double csh = gmat.Cosh(dif);
        const double lgLoss = gmat.Log(csh);
        errors.Add(lgLoss);
    }
    const double sum = errors.Sum();
    //cout << "Errors = " << errors.Print() << endl;
    return sum;
    //return loss;
}

/*def quantile_loss(q, y, f):
  # q: Quantile to be evaluated, e.g., 0.5 for median.
  # y: True value.
  # f: Fitted (predicted) value.
  e = y - f
  return np.maximum(q * e, (q - 1) * e)
  */
double LossFunctions::GetQuantileMAE(const VecD & diffs, const double quantile) const
{
    const GeneralMath gmat;
    double sum = 0;
    for (const double dif : diffs)
    {
        const double one = gmat.Fabs(dif) *  quantile;
        const double two = gmat.Fabs(dif) * (quantile - 1);
        //const double two = (1 - quantile) * dif; // ?
        const double maxx = AlgoSTDThin().Max(one, two);
        sum += maxx;
    }
    return sum;
}
