#ifndef OPTIMULTIBINSEARCH_H
#define OPTIMULTIBINSEARCH_H

#include "../../Util/Result.hpp"
#include "../../Util/VecD.hpp"
#include <Math/MultiDimIter/IMultiDimIterConsumerTpl.hpp>

namespace EnjoLib
{
    class OptiMultiSubject;

    class OptiMultiBinSearch : public IMultiDimIterConsumerTpl
    {
        public:
            OptiMultiBinSearch();
            virtual ~OptiMultiBinSearch();

            Result<VecD > Run( OptiMultiSubject & subj, int numSlices = 6, double eps = 0.001);

            void Consume(const EnjoLib::VecD & data) override;
        protected:
        private:
           mutable VecD m_vopt;
           mutable double m_yopt = 0;
           mutable double m_epsReached = 0;
           mutable OptiMultiSubject * m_subj;

    };

}
#endif // OPTIMULTIBINSEARCH_H
