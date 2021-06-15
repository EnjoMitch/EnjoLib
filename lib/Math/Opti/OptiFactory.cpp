#include "OptiFactory.hpp"
#include <Util/Except.hpp>
#include "OptiBinSearch.hpp"
#include "OptiBrent.hpp"
#include <Template/CorradePointer.h>

using namespace EnjoLib;

OptiFactory::OptiFactory(){}
OptiFactory::~OptiFactory(){}

Corrade::Containers::Pointer<IOptiAlgo> OptiFactory::Create(OptiType type, double minArg, double maxArg, double eps)
{
    switch (type)
    {
    case OPTI_BIN_SEARCH:
        return Corrade::Containers::Pointer<IOptiAlgo>(new OptiBinSearch(minArg, maxArg, eps));
    case OPTI_BRENT:
        return Corrade::Containers::Pointer<IOptiAlgo>(new OptiBrent(minArg, maxArg, eps));
    }

    throw ExceptInvalidArg("Not handled OptiType");
}
