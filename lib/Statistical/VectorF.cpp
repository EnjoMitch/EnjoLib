#include "VectorF.hpp"

using namespace EnjoLib;

VectorF::VectorF( const std::vector<double> & init )
{
    Init(init);
}

VectorF::VectorF( const std::vector<float> & init )
: VectorTpl(init)
{}

VectorF::VectorF( const std::vector<bool> & init )
: VectorTpl(init)
{}

VectorF::VectorF( int n )
: VectorTpl(n)
{}

VectorF::VectorF(){}

VectorF::~VectorF(){}
