#ifndef VECTORF_H
#define VECTORF_H

#include "VectorTpl.hpp"

namespace EnjoLib
{
class VectorF : public VectorTpl<float>
{
    public:
        VectorF( const std::vector<double> & init );
        VectorF( const std::vector<float> & init );
        VectorF( const std::vector<bool> & init );
        VectorF( int n );
        VectorF();
        virtual ~VectorF();
    protected:
    private:
};
}

#endif // VECTORF_H
