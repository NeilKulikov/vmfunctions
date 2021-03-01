#ifndef VMFUNCTIONS_COMMON
#define VMFUNCTIONS_COMMON

#include <type_traits>

namespace vmfunctions::common {

template<typename I>
constexpr I factorial(I arg) {
    static_assert(std::is_integral<I>::value);
    return arg == 0 ? I(1) : arg * factorial(arg - 1);
}

template<typename F, typename I = int>
constexpr F rfactorial(I deg) {
    static_assert(std::is_floating_point<F>::value);
    static_assert(std::is_integral<I>::value);
    static_assert(std::is_signed<I>::value);
    return F(1) / F(factorial<I>(deg)); 
}

template<typename F, int pow>
constexpr F power(F arg) {
    return pow ? arg * power<F, pow - 1>(arg) : F(1); 
}

template<typename F>
constexpr F power(F arg, int pow) {
    return pow ? arg * power<F>(arg, pow - 1) : F(1); 
}

} // vmfunctions::common

#endif // VMFUNCTIONS_COMMON