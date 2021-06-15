#include "IOptiAlgo.hpp"

using namespace EnjoLib;

IOptiAlgo::IOptiAlgo()
: m_discrete(false)
{
    //ctor
}

IOptiAlgo::~IOptiAlgo()
{
    //dtor
}

void IOptiAlgo::SetDiscrete()
{
    m_discrete = true;
}
bool IOptiAlgo::IsDiscrete() const
{
    return m_discrete;
}
