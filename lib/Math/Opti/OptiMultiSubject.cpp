#include "OptiMultiSubject.hpp"
#include <Template/Array.hpp>

using namespace EnjoLib;

OptiMultiSubject::OptiMultiSubject()
{
    //ctor
}

OptiMultiSubject::~OptiMultiSubject()
{
    //dtor
}

EnjoLib::Array<OptiMultiSubject::Bounds> OptiMultiSubject::GetBounds() const { return EnjoLib::Array<OptiMultiSubject::Bounds>(); };