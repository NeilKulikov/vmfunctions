#ifndef VMFUNCTIONS_TRIGINOMETRY_SIN_UNBALANCED
#define VMFUNCTIONS_TRIGINOMETRY_SIN_UNBALANCED

#include <type_traits>

#include "vmfunctions/constants.hpp"
#include "vmfunctions/type_manipulations.hpp"
#include "vmfunctions/trigonometry/sin_series.hpp"

namespace vmfunctions::trigonometry {

template<typename F, int deg = sizeof(F)>
inline F sinn(F arg) {
    using namespace vmfunctions::constants;
    return sins<F, deg>(arg * hpi<F>);
}

template<typename F, int deg = sizeof(F)>
inline F sinu(F arg) {
    using namespace vmfunctions::common;
    using namespace vmfunctions::constants;
    constexpr F shifts[] = {0, pi<F>, pi<F>, dpi<F>};
    using I = typename coupled_type<F>::type;
    // Equals to the following line
    // const I aper = I(arg * dpi<F>) % 4;
    const I iarg = I(pih<F> * arg);
    const I aper = iarg & I(3);
    const F argshift = shifts[aper];
    constexpr int asshift = 8 * sizeof(F) - 1;
    const auto argsign = 
                    reinterpret<F>((aper ^ 1) << asshift);
    constexpr int gsshift = 8 * sizeof(F) - 2;
    const auto gensign = 
                    reinterpret<F>((aper & 2) << gsshift);
    return 
        XOR(sins<F, deg>(XOR(argshift - arg, argsign)), gensign);
}

} // vmfunctions::trigonometry

#endif // VMFUNCTIONS_TRIGINOMETRY_SIN_UNBALANCED