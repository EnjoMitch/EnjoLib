#include "OptiMultiRosenbrok.h"
#include "Rosenbrok.h"
#include <STD/VectorCpp.hpp>

using namespace EnjoLib;

OptiMultiRosenbrok::OptiMultiRosenbrok()
{
    //ctor
}

OptiMultiRosenbrok::~OptiMultiRosenbrok()
{
    //dtor
}

/*
double OptiMultiRosenbrok::UpdateGetValue( double arg )
{
   return arg * arg;
}
*/
double OptiMultiRosenbrok::Get(const EnjoLib::VecD & in)
{
    return 0;
}
double OptiMultiRosenbrok::Get(const double * in, int n)
{
    return Rosenbrok().Eval(in);
}
EnjoLib::VecD OptiMultiRosenbrok::GetStart() const
{
    EnjoLib::VecD ret;
    ret.push_back(-1.2);
    ret.push_back(1);
    return ret;
}
EnjoLib::VecD OptiMultiRosenbrok::GetStep() const
{
    EnjoLib::VecD ret;
    ret.push_back(1);
    ret.push_back(1);
    return ret;
}

std::vector<OptiMultiSubject::Bounds> OptiMultiRosenbrok::GetBounds() const
{
    std::vector<OptiMultiSubject::Bounds> ret;
    ret.push_back(OptiMultiSubject::Bounds(-3, 3));
    ret.push_back(OptiMultiSubject::Bounds(-3, 3));
    return ret;
}
