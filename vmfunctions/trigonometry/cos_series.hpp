#ifndef VMFUNCTIONS_TRIGINOMETRY_COS_SERIES
#define VMFUNCTIONS_TRIGINOMETRY_COS_SERIES

#include <type_traits>

#include "vmfunctions/trigonometry/cos_coefs.hpp"

namespace vmfunctions::trigonometry {

template<typename F, int deg = sizeof(F)>
inline F coss(F arg) {
    F const arg2{arg * arg};
    F res{coscoef<F>(2 * deg + 2)};
    #pragma unroll(deg)
    for(int d = deg; 0 < d; --d) {
        res  = res * arg2 + coscoef<F>(2 * d);
    }
    return res * arg2 + F(1);
}

} // vmfunctions::trigonometry

#endif // VMFUNCTIONS_TRIGINOMETRY_COS_SERIES