#ifndef VMFUNCTIONS_TESTS_INTERNAL
#define VMFUNCTIONS_TESTS_INTERNAL

#include "catch2/catch.hpp"

#define STD_RTOL 1.e-5
#define STD_ATOL 1.e-7

#define ALMOST_EQUAL_CUSTOM(gtr, res, rtol, atol) REQUIRE(is_almost_equal(gtr, res, rtol, atol))
#define ALMOST_EQUAL_REL(gtr, res, rtol) ALMOST_EQUAL_CUSTOM(gtr, res, rtol, decltype(gtr)(STD_ATOL))
#define ALMOST_EQUAL_ABS(gtr, res, atol) ALMOST_EQUAL_CUSTOM(gtr, res, decltype(gtr)(STD_RTOL), atol))
#define ALMOST_EQUAL(gtr, res) ALMOST_EQUAL_CUSTOM(gtr, res, decltype(gtr)(STD_RTOL), decltype(gtr)(STD_ATOL))

template<typename T>
bool is_almost_equal(const T gt, const T res, 
        const T rtol = T(STD_RTOL), const T atol = T(STD_ATOL)) {
    const T adiff = res - gt;
    if ((-atol <= adiff) && (adiff < atol)) {
        return true;
    } else {
        const T rdiff = adiff / std::max(gt, res);
        if ((-rtol <= rdiff) && (rdiff < rtol)) {
            return true;
        }
    }
    return false;
}

#endif // VMFUNCTIONS_TESTS_INTERNAL