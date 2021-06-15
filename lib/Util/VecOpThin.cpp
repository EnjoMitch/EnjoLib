#include "VecOpThin.hpp"
#include <Util/VecD.hpp>
#include <STD/VectorCpp.hpp>
#include <STD/Algorithm.hpp>

using namespace EnjoLib;


void VecOpThin::AddRef(const EnjoLib::VecD & a, EnjoLib::VecD * two) const
{
    std::copy (a.Data().begin(), a.Data().end(), std::back_inserter(*two));
}