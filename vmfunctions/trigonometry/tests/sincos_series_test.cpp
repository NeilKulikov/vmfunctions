#ifndef CATCH_CONFIG_MAIN
    #define CATCH_CONFIG_MAIN
#endif

#include "catch2/catch.hpp"

#include <cmath>

#include "vmfunctions/tests/tests_common.hpp"
#include "vmfunctions/trigonometry/cos_series.hpp"
#include "vmfunctions/trigonometry/sin_series.hpp"

#include "vmfunctions/trigonometry/tests/residue.hpp"

using fp_types = std::tuple<float, double>;

TEMPLATE_LIST_TEST_CASE("cos zero exact", "[cos][series]", fp_types) {
    REQUIRE(vmfunctions::trigonometry::coss<TestType>(0) == TestType(1.0));
}

TEMPLATE_LIST_TEST_CASE("cos series", "[cos][series]", fp_types) {
    const auto coss = std::bind(
        vmfunctions::trigonometry::coss<TestType>, std::placeholders::_1);
    const int nsteps = 256;
    const TestType from = 0, to = M_PI_2;
    const TestType step = (to - from) / TestType(nsteps);
    for(int i = 0; i < nsteps; ++i) {
        const TestType x = from + step * TestType(i);
        const TestType cos = std::cos(x);
        const TestType res = coss(x);
        ALMOST_EQUAL_CUSTOM(res, cos, TestType(1.e-3), TestType(1.e-5));
    }
}

TEMPLATE_LIST_TEST_CASE("sin zero exact", "[sin][series]", fp_types) {
    REQUIRE(vmfunctions::trigonometry::sins<TestType>(0) == TestType(0.0));
}

TEMPLATE_LIST_TEST_CASE("sin series", "[sin][series]", fp_types) {
    const auto sins = std::bind(
        vmfunctions::trigonometry::sins<TestType>, std::placeholders::_1);
    const int nsteps = 256;
    const TestType from = 0, to = M_PI_2;
    const TestType step = (to - from) / TestType(nsteps);
    for(int i = 0; i < nsteps; ++i) {
        const TestType x = from + step * TestType(i);
        const TestType sin = std::sin(x);
        const TestType res = sins(x);
        ALMOST_EQUAL_CUSTOM(res, sin, TestType(1.e-3), TestType(1.e-5));
    }
}
