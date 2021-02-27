#ifndef VMFUNCTIONS_TRIGINOMETRY_SIN_COEFS
#define VMFUNCTIONS_TRIGINOMETRY_SIN_COEFS

#include <type_traits>

#include "vmfunctions/common.hpp"

namespace vmfunctions::trigonometry {

template<typename F, typename I = int>
constexpr F sinsign(I deg) {
    static_assert(std::is_floating_point<F>::value);
    static_assert(std::is_integral<I>::value);
    static_assert(std::is_signed<I>::value);
    return ((deg + 1) % 4) ? F(1) : F(-1); 
}

template<typename F, typename I = int>
constexpr F sineven(I deg) {
    static_assert(std::is_floating_point<F>::value);
    static_assert(std::is_integral<I>::value);
    static_assert(std::is_signed<I>::value);
    return (deg % 2) ? F(1) : F(0); 
}

template<typename F, typename I = int>
constexpr F sincoef(I deg) {
    static_assert(std::is_floating_point<F>::value);
    static_assert(std::is_integral<I>::value);
    static_assert(std::is_signed<I>::value);
    return sineven<F, I>(deg) * sinsign<F, I>(deg) 
                    * common::rfactorial<F, I>(deg);
}

} // vmfunctions::trigonometry

#endif // VMFUNCTIONS_TRIGINOMETRY_SIN_COEFS