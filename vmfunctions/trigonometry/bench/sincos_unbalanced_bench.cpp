#ifndef CATCH_CONFIG_MAIN
    #define CATCH_CONFIG_MAIN
#endif

#ifndef CATCH_CONFIG_ENABLE_BENCHMARKING
    #define CATCH_CONFIG_ENABLE_BENCHMARKING
#endif

#include "catch2/catch.hpp"

#include <cmath>
#include <type_traits>

#include "vmfunctions/trigonometry/sin_unbalanced.hpp"

using test_types = std::tuple<float, double>;

TEMPLATE_LIST_TEST_CASE("sin unbalanced", "[sin][unbalanced]", test_types) {
    const auto sinu = std::bind(
        vmfunctions::trigonometry::sinu<TestType>, std::placeholders::_1);
    
    BENCHMARK("Sin Unbalanced 1. - 1") {
        return sinu(1.);
    };

    BENCHMARK("Loop - 1024") {
        constexpr int nsteps = 1024;
        volatile TestType res = 0.;
        for(int i = 0; i < nsteps; ++i) {
            res += TestType(1.);
        }
    };

    BENCHMARK("Sin Unbalanced 1. - 1024") {
        constexpr int nsteps = 1024;
        volatile TestType res = 0.;
        for(int i = 0; i < nsteps; ++i) {
            res += sinu(1.);
        }
    };

    BENCHMARK("Sin Std 1. - 1024") {
        constexpr int nsteps = 1024;
        volatile TestType res = 0.;
        for(int i = 0; i < nsteps; ++i) {
            if constexpr (std::is_same<float, TestType>::value) {
                res += std::sinf(1.);
            }
            if constexpr (std::is_same<double, TestType>::value) {
                res += std::sin(1.);
            }
        }
    };
}
