#ifndef VECTORD_H
#define VECTORD_H

#include "VectorTpl.hpp"

namespace EnjoLib
{
class VectorD : public VectorTpl<double>
{
    public:
        VectorD( const EnjoLib::Str & data );
        VectorD( const std::vector<double> & init );
        VectorD( const std::vector<float> & init )
        {
            Init(init);
        }
        VectorD( const std::vector<bool> & init );
        VectorD( int n );
        VectorD( int n, double val );
        VectorD();
        virtual ~VectorD();
    protected:
    private:
};
}
#endif // VECTORD_H
