#ifndef EL_FP_H
#define EL_FP_H

namespace EnjoLib
{
#ifdef EL_FLOATING_POINT_LOW_PRECISION
    using FP = float;
#else
    using FP = double;
#endif // EL_FLOATING_POINT_LOW_PRECISION
}


#endif // EL_FP_H
