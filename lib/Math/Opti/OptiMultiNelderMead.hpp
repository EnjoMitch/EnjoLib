#ifndef OPTIMULTINELDERMEAD_H
#define OPTIMULTINELDERMEAD_H

#include <Util/VecFwd.hpp>
#include "../../Util/Result.hpp"

namespace EnjoLib
{
    class OptiMultiSubject;

    class OptiMultiNelderMead
    {
        public:
            OptiMultiNelderMead();
            virtual ~OptiMultiNelderMead();

            Result<VecD > Run( OptiMultiSubject & subj, FP eps = 0.00001, int konvge = 10, int kcount = 500 ) const;
        protected:
        private:
    };
}

#endif // OPTIMULTINELDERMEAD_H
