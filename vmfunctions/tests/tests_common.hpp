#ifndef VMFUNCTIONS_TESTS_COMMON
#define VMFUNCTIONS_TESTS_COMMON

#include "catch2/catch.hpp"


#define STD_RTOL 1.e-5
#define STD_ATOL 1.e-7

#define ALMOST_EQUAL_CUSTOM(gtr, res, rtol, atol) check_almost_equal(gtr, res, rtol, atol)
#define ALMOST_EQUAL_REL(gtr, res, rtol) ALMOST_EQUAL_CUSTOM(gtr, res, rtol, decltype(gtr)(STD_ATOL))
#define ALMOST_EQUAL_ABS(gtr, res, atol) ALMOST_EQUAL_CUSTOM(gtr, res, decltype(gtr)(STD_RTOL), atol)
#define ALMOST_EQUAL(gtr, res) ALMOST_EQUAL_CUSTOM(gtr, res, decltype(gtr)(STD_RTOL), decltype(gtr)(STD_ATOL))

template<typename Last>
constexpr auto max(Last l) {
    return l;
}

template<typename First, typename Last>
constexpr auto max(First f, Last l) {
    return (f >= l) ? f : l;
}

template<typename First, typename... Tail>
constexpr auto max(First f, Tail... t) {
    return max(f, max(t...));
}

template<typename T>
constexpr auto abs(T x) {
    return (x >= 0) ? x : -x;
}

template<typename T>
void check_almost_equal(const T gt, const T rs, 
        const T rtol = T(STD_RTOL), const T atol = T(STD_ATOL)) {
    CAPTURE(gt, rs, rtol, atol);
    if(gt == rs) return;
    const T aerr = rs - gt;
    CAPTURE(aerr);
    if((-atol <= aerr) && (aerr <= +atol)) {
        const T div = max(abs(rs), abs(gt), atol);
        const T rerr = aerr / div;
        CAPTURE(rerr);
        REQUIRE(-rtol <= rerr);
        REQUIRE(rerr <= +rtol);
    } else {
        REQUIRE(-atol <= aerr);
        REQUIRE(aerr <= +atol);
    }
}

#endif // VMFUNCTIONS_TESTS_COMMON