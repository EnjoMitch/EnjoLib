#include "Loss.hpp"

#include "../Math/GeneralMath.hpp"
#include <Util/Str.hpp>
#include <Util/PimplCopier.hpp>
#include <Util/PimplDeleter.hpp>
#include <Util/Osstream.hpp>

#include <STD/Ostream.hpp>
#include <STD/Map.hpp>
#include <iomanip>

using namespace std;
using namespace EnjoLib;
// SharedPtr<stdfwd::map<int, VecD>>

struct Loss::Impl
{
    std::map<int, VecD> labelIdErrors;
};

PIMPL_COPIER(Loss)
PIMPL_DELETER(Loss)

Loss::Loss(double psum, double pstdDev)
//: labelIdErrors(new std::map<int, VecD>)
: m_impl(new Impl)
{
    sum = psum;
    stdDev = pstdDev;
}

Loss::~Loss()
{
    //dtor
}

double Loss::GetRelDiff() const
{
    if (sum == 0)
        return 0;

    const double relDiff = stdDev / sum;
    return relDiff;
}

EnjoLib::Str Loss::PrintRel() const
{
    Osstream oss;
    const GeneralMath gmat;
    oss.OStr() << "loss = " << gmat.round(sum*100)/100.0 << " ± " << setprecision(3) << GetRelDiff() * 100 << " % ";
    return oss.str();
}


bool Loss::operator < (const Loss & other) const
{
    return sum < other.sum;
}

bool Loss::operator == (const int64_t & i) const
{
    return sum == i;
}

const std::map<int, VecD> & Loss::labelIdErrors() const
{
    return GetImpl().labelIdErrors;
}
std::map<int, VecD> & Loss::labelIdErrors()
{
    return GetImplRW().labelIdErrors;
}
