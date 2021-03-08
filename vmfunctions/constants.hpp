#ifndef VMFUNCTIONS_CONSTANTS
#define VMFUNCTIONS_CONSTANTS

#define __VMF_C_PI 3.141592653589793238462643383279

namespace vmfunctions::constants {

template<typename F>
inline constexpr F pi = F(__VMF_C_PI);

template<typename F>
inline constexpr F dpi = pi<F> * F(2);

template<typename F>
inline constexpr F pih = F(2) / pi<F>;

template<typename F>
inline constexpr F hpi = pi<F> / F(2);

} // vmfunctions::constants

#undef __VMF_C_PI

#endif // VMFUNCTIONS_CONSTANTS