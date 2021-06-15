#ifndef MULTIDIMITERCONSUMERTPL_H
#define MULTIDIMITERCONSUMERTPL_H

#include <Util/VecD.hpp>

namespace EnjoLib
{
    class IMultiDimIterConsumerTpl
    {
        public:
            IMultiDimIterConsumerTpl(){}
            virtual ~IMultiDimIterConsumerTpl(){}

            virtual void Consume(const VecD & data) = 0;
        protected:
        private:
    };
}


#endif // MULTIDIMITERCONSUMERTPL_H
