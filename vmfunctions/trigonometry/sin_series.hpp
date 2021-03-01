#ifndef VMFUNCTIONS_TRIGINOMETRY_SIN_SERIES
#define VMFUNCTIONS_TRIGINOMETRY_SIN_SERIES

#include <type_traits>

#include "vmfunctions/trigonometry/sin_coefs.hpp"

namespace vmfunctions::trigonometry {

template<typename F, int deg = sizeof(F)>
inline F sins(F arg) {
    F const arg2{arg * arg};
    F res{sincoef<F>(2 * deg + 1)};
    #pragma unroll(deg)
    for(int d = deg; 0 < d; --d) {
        res  = res * arg2 + sincoef<F>(2 * d - 1);
    }
    return arg * res;
}

} // vmfunctions::trigonometry

#endif // VMFUNCTIONS_TRIGINOMETRY_SIN_SERIES