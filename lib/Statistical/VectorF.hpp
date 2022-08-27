#ifndef VECTORF_H
#define VECTORF_H

#include "VectorTpl.hpp"
#include <3rdParty/stdfwd.hh>

namespace EnjoLib
{
class VectorF : public VectorTpl<float>
{
    public:
        VectorF( const std::vector<double> & init );
        VectorF( const std::vector<float> & init );
        VectorF( const std::vector<bool> & init );
        VectorF( int n );
        VectorF( int n, float val);
        VectorF( const STDFWD::string & data);
        VectorF( const char * data);
        VectorF();
        virtual ~VectorF();
    protected:
    private:
};
}

#endif // VECTORF_H
