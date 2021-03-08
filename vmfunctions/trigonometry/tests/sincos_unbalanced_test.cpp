#ifndef CATCH_CONFIG_MAIN
    #define CATCH_CONFIG_MAIN
#endif

#include "catch2/catch.hpp"

#include <cmath>

#include "vmfunctions/tests/tests_common.hpp"
#include "vmfunctions/trigonometry/sin_unbalanced.hpp"

using test_types = std::tuple<float, double>;

TEMPLATE_LIST_TEST_CASE("sin series", "[sin][series]", test_types) {
    const auto sinu = std::bind(
        vmfunctions::trigonometry::sinu<TestType>, std::placeholders::_1);
    const int nsteps = 1024;
    const TestType from = 0, to = +5 *  M_PI;
    const TestType step = (to - from) / TestType(nsteps);
    for(int i = 0; i < nsteps; ++i) {
        const TestType x = from + step * TestType(i);
        const TestType sin = std::sin(x);
        const TestType res = sinu(x);
        CAPTURE(x, sin, res);
        ALMOST_EQUAL_CUSTOM(res, sin, TestType(1.e-2), TestType(1.e-5));
    }
}
