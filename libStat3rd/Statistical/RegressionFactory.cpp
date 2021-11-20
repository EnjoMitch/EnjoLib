#include "RegressionFactory.hpp"

using namespace EnjoLib;
RegressionFactory::RegressionFactory()
{
    //ctor
}

RegressionFactory::~RegressionFactory()
{
    //dtor
}

/*
#include "RegressionRegression3.hpp"
#include "RegressionMKL.hpp"
#include "RegressionNumpy.hpp"
#include "RegressionNewmat10.hpp"
*/
/*
Corrade::Containers::Pointer<RegressionAbstract> RegressionAbstract::CreateRegression3()
{
    return Corrade::Containers::Pointer<RegressionAbstract>(new RegressionRegression3());
}
Corrade::Containers::Pointer<RegressionAbstract> RegressionAbstract::CreateDefault()
{
    //return CreateNewmat(); /// TODO: Errors in tests, just like MKL! Ergo: wrong Regression or tests!
    return CreateMKL();
}
Corrade::Containers::Pointer<RegressionAbstract> RegressionAbstract::CreateMKL()
{
    return Corrade::Containers::Pointer<RegressionAbstract>(new RegressionMKL());
}

#ifdef USE_LIB_NEWMAT
Corrade::Containers::Pointer<RegressionAbstract> RegressionAbstract::CreateNewmat()
{
    return Corrade::Containers::Pointer<RegressionAbstract>(new RegressionNewmat10());
}
#endif

Corrade::Containers::Pointer<RegressionAbstract> RegressionAbstract::CreateNumpy()
{
    return Corrade::Containers::Pointer<RegressionAbstract>(new RegressionNumpy());
}
EIGENTYPE_DEFAULT,
    EIGENTYPE_EIGEN3,
    EIGENTYPE_MKL,
    EIGENTYPE_NEWMAT,
    EIGENTYPE_NUMPY
    */
    
#include "3rdParty/RegressionGSL.hpp"
#include "3rdParty/RegressionEigen.hpp"
//#include "RegressionAF.h"
#include <Util/Except.hpp>
#include <Template/CorradePointer.h>

Corrade::Containers::Pointer<RegressionAbstract> RegressionFactory::CreateDefault() const
{
    return Create(RegressionAbstract::RegType::REG_EIGEN);
}

Corrade::Containers::Pointer<RegressionAbstract> RegressionFactory::Create(const RegressionAbstract::RegType & eigType) const
{
    return Corrade::Containers::Pointer<RegressionAbstract>(new RegressionEigen());
}

/*
#include "RegressionGSL.h"
#include "RegressionEigen.h"
//#include "RegressionAF.h"
#include <Util/Except.hpp>
#include <Template/CorradePointer.h>
Corrade::Containers::Pointer<RegressionAbstract> RegressionAbstract::Create(const RegressionAbstract::RegType & type)
{
    switch (type)
    {
        case RegType::REG_GSL:      return Corrade::Containers::Pointer<RegressionAbstract>(new RegressionGSL());
        case RegType::REG_EIGEN:    return Corrade::Containers::Pointer<RegressionAbstract>(new RegressionEigen());
        //case RegType::REG_AFIRE:    return Corrade::Containers::Pointer<RegressionAbstract>(new RegressionAF());
        case RegType::REG_AFIRE:    return Corrade::Containers::Pointer<RegressionAbstract>(new RegressionEigen());
    }
    throw EnjoLib::ExceptRuntimeError("RegressionAbstract::Create() Not handled.");
}

Corrade::Containers::Pointer<RegressionAbstract> RegressionAbstract::CreateDefault()
{
    return Create(RegType::REG_EIGEN);
}
*/