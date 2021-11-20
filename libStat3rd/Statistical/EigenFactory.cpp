#include <Statistical/EigenFactory.hpp>

using namespace EnjoLib;
EigenFactory::EigenFactory()
{
    //ctor
}

EigenFactory::~EigenFactory()
{
    //dtor
}

#include "3rdParty/EigenEigen3.hpp"
#include "3rdParty/EigenMKL.hpp"
#include "3rdParty/EigenNumpy.hpp"
#include "3rdParty/EigenNewmat10.hpp"

/*
Corrade::Containers::Pointer<EigenAbstract> EigenAbstract::CreateEigen3()
{
    return Corrade::Containers::Pointer<EigenAbstract>(new EigenEigen3());
}
Corrade::Containers::Pointer<EigenAbstract> EigenAbstract::CreateDefault()
{
    //return CreateNewmat(); /// TODO: Errors in tests, just like MKL! Ergo: wrong Eigen or tests!
    return CreateMKL();
}
Corrade::Containers::Pointer<EigenAbstract> EigenAbstract::CreateMKL()
{
    return Corrade::Containers::Pointer<EigenAbstract>(new EigenMKL());
}

#ifdef USE_LIB_NEWMAT
Corrade::Containers::Pointer<EigenAbstract> EigenAbstract::CreateNewmat()
{
    return Corrade::Containers::Pointer<EigenAbstract>(new EigenNewmat10());
}
#endif

Corrade::Containers::Pointer<EigenAbstract> EigenAbstract::CreateNumpy()
{
    return Corrade::Containers::Pointer<EigenAbstract>(new EigenNumpy());
}
EIGENTYPE_DEFAULT,
    EIGENTYPE_EIGEN3,
    EIGENTYPE_MKL,
    EIGENTYPE_NEWMAT,
    EIGENTYPE_NUMPY
    */
Corrade::Containers::Pointer<EigenAbstract> EigenFactory::Create(const EigenType & eigType) const
{
    return Corrade::Containers::Pointer<EigenAbstract>(new EigenEigen3());
}