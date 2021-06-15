#ifndef EIGENNUMPY_HPP
#define EIGENNUMPY_HPP

#include "../EigenAbstract.hpp"

namespace EnjoLib
{
class EigenNumpy : public EigenAbstract
{
    public:
        EigenNumpy();
        virtual ~EigenNumpy();

    protected:
        stdfwd::vector<EigenValueVector> GetEigenValVecClient( const Matrix & m ) const;

    private:
};
}


#endif // EIGENNUMPY_HPP
