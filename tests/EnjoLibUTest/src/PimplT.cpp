#include "PimplT.hpp"
#include <Util/PimplDeleter.hpp>
#include <Util/PimplCopier.hpp>

using namespace std;
//using namespace EnjoLib;

struct Pimp::Impl
{
    double dat = 2;
};
PIMPL_DELETER(Pimp)

Pimp::Pimp()
: m_impl(new Impl())
{

}
double Pimp::Dat() const
{
    return GetImpl().dat;
}

struct PimpNotInit::Impl
{
    double dat = 0;
};
PIMPL_DELETER(PimpNotInit)

double PimpNotInit::Dat() const
{
    return GetImpl().dat;
}

struct PimpCpy::Impl
{
    double dat = 2;
};

PIMPL_DELETER(PimpCpy)
PIMPL_COPIER(PimpCpy)

PimpCpy::PimpCpy()
: m_impl(new Impl())
{

}
double PimpCpy::Dat() const
{
    return GetImpl().dat;
}
double & PimpCpy::RW()
{
    return GetImplRW().dat;
}
