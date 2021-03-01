#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include <cmath>

#include "vmfunctions/tests/tests_common.hpp"
#include "vmfunctions/trigonometry/tests/residue.hpp"

using fp_types = std::tuple<float, double>;

TEMPLATE_LIST_TEST_CASE("sin residue 2", "[sin][residue]", fp_types) {
    using namespace vmfunctions::trigonometry::tests;
    const auto residue = 
        [](const auto x) { return sin_residue<TestType, 2>(x); };
    ALMOST_EQUAL(TestType(-1. / 6.), residue(1.));
    ALMOST_EQUAL(TestType(-0.08074551218828077), residue(M_PI_4));
}

TEMPLATE_LIST_TEST_CASE("sin residue 3", "[sin][residue]", fp_types) {
    using namespace vmfunctions::trigonometry::tests;
    const auto residue = 
        [](const auto x) { return sin_residue<TestType, 4>(x); };
    ALMOST_EQUAL(TestType(+1. / 120.), residue(1.));
    ALMOST_EQUAL(TestType(+0.00249039457019272), residue(M_PI_4));
}