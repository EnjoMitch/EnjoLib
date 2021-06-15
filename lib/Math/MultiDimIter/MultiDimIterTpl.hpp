#ifndef MULTIDIMITERTPL_H
#define MULTIDIMITERTPL_H

#include <Statistical/Matrix.hpp>

namespace EnjoLib
{
class IMultiDimIterConsumerTpl;
class MultiDimIterTpl
{
    public:
        MultiDimIterTpl(){}
        virtual ~MultiDimIterTpl(){}

        typedef VecD Vt;
        typedef Matrix VVt;

        void StartIteration(const Matrix & data, IMultiDimIterConsumerTpl & consumer);
    protected:
    private:
        void IterateTpl(IMultiDimIterConsumerTpl & consumer, const VVt & data, Vt & res, unsigned d = 0);


};
}

#endif // MULTIDIMITERTPL_H
