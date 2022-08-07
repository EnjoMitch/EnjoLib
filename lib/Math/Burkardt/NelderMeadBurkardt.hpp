#include <Math/FP.hpp>

namespace EnjoLib{
class OptiMultiSubject;
}

namespace NelderMeadBurkardt
{
    void nelmin ( EnjoLib::OptiMultiSubject & subj, int n, EnjoLib::FP start[], EnjoLib::FP xmin[],
      EnjoLib::FP *ynewlo, EnjoLib::FP reqmin, const EnjoLib::FP step[], int konvge, int kcount,
      int *icount, int *numres, int *ifault );
    void timestamp ( );
}
