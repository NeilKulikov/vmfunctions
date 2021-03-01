#ifndef VMFUNCTIONS_TRIGINOMETRY_TESTS_RESIDUE
#define VMFUNCTIONS_TRIGINOMETRY_TESTS_RESIDUE

#include <cmath>
#include <type_traits>

#include "vmfunctions/common.hpp"

namespace vmfunctions::trigonometry::tests {

//Provides info about upper bound of residue
//in range [0, pi/2]
template<typename F, int deg = sizeof(F)>
constexpr F sin_residue(F arg) {
    using namespace vmfunctions::common;
    constexpr int ndeg = deg + 1;
    constexpr F signs[] = { 1, 1, -1, -1 };
    constexpr F sign = signs[ndeg % 4];
    return sign
            * power<F>(arg, ndeg)
            * rfactorial<F>(ndeg);
} 

//Provides info about upper bound of residue
//in range [0, pi/2]
template<typename F, int deg = sizeof(F)>
constexpr F cos_residue(F arg) {
    using namespace vmfunctions::common;
    constexpr int ndeg = deg + 1;
    constexpr F signs[] = { -1, -1, 1, 1 };
    constexpr F sign = signs[ndeg % 4];
    return sign
            * power<F>(arg, ndeg)
            * rfactorial<F>(ndeg);
}

} // vmfunctions::trigonometry::tests

#endif // VMFUNCTIONS_TRIGINOMETRY_TESTS_RESIDUE