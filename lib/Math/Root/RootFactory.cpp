#include "RootFactory.hpp"
#include <Util/Except.hpp>
#include "RootBisection.hpp"
#include "RootBrent.hpp"
#include <Template/CorradePointer.h>

using namespace EnjoLib;

RootFactory::RootFactory(){}
RootFactory::~RootFactory(){}

Corrade::Containers::Pointer<IRootAlgo> RootFactory::Create(RootType type, double minArg, double maxArg, double eps)
{
    switch (type)
    {
    case ROOT_BIN_SEARCH:
        return Corrade::Containers::Pointer<IRootAlgo>(new RootBisection(minArg, maxArg, eps));
    case ROOT_BRENT:
        return Corrade::Containers::Pointer<IRootAlgo>(new RootBrent(minArg, maxArg, eps));
    }

    throw ExceptInvalidArg("Not handled RootType");
}
