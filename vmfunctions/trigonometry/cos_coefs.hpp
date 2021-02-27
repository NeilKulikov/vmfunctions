#ifndef VMFUNCTIONS_TRIGINOMETRY_COS_COEFS
#define VMFUNCTIONS_TRIGINOMETRY_COS_COEFS

#include <type_traits>

#include "vmfunctions/common.hpp"

namespace vmfunctions::trigonometry {

template<typename F, typename I = int>
constexpr F cossign(I deg) {
    static_assert(std::is_floating_point<F>::value);
    static_assert(std::is_integral<I>::value);
    static_assert(std::is_signed<I>::value);
    return (deg % 4) ? F(-1) : F(1); 
}

template<typename F, typename I = int>
constexpr F coseven(I deg) {
    static_assert(std::is_floating_point<F>::value);
    static_assert(std::is_integral<I>::value);
    static_assert(std::is_signed<I>::value);
    return (deg % 2) ? F(0) : F(1); 
}

template<typename F, typename I = int>
constexpr F coscoef(I deg) {
    static_assert(std::is_floating_point<F>::value);
    static_assert(std::is_integral<I>::value);
    static_assert(std::is_signed<I>::value);
    return coseven<F, I>(deg) * cossign<F, I>(deg) 
                    * common::rfactorial<F, I>(deg);
}

} // vmfunctions::trigonometry

#endif // VMFUNCTIONS_TRIGINOMETRY_COS_COEFS