#ifndef CATCH_CONFIG_MAIN
    #define CATCH_CONFIG_MAIN
#endif

#ifndef CATCH_CONFIG_ENABLE_BENCHMARKING
    #define CATCH_CONFIG_ENABLE_BENCHMARKING
#endif

#include "catch2/catch.hpp"

#include <cmath>
#include <type_traits>

#include "vmfunctions/trigonometry/sin_series.hpp"

using test_types = std::tuple<float, double>;

TEMPLATE_LIST_TEST_CASE("sin series", "[sin][series]", test_types) {
    const auto sins = std::bind(
        vmfunctions::trigonometry::sins<TestType>, std::placeholders::_1);
    
    BENCHMARK("Sin Series 1. - 1") {
        return sins(1.);
    };

    BENCHMARK("Sin Std 1. - 1") {
        if constexpr (std::is_same<float, TestType>::value) {
            return std::sinf(1.);
        }
        else {
            return std::sin(1.);
        }
    };

    BENCHMARK("Loop Series - 1024") {
        constexpr int nsteps = 1024;
        volatile TestType res = 0.;
        for(int i = 0; i < nsteps; ++i) {
            res += TestType(1.);
        }
    };

    BENCHMARK("Sin Series 1. - 1024") {
        constexpr int nsteps = 1024;
        volatile TestType res = 0.;
        for(int i = 0; i < nsteps; ++i) {
            res += sins(1.);
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

#include "vmfunctions/trigonometry/cos_series.hpp"

TEMPLATE_LIST_TEST_CASE("cos series", "[cos][series]", test_types) {
    const auto coss = std::bind(
        vmfunctions::trigonometry::coss<TestType>, std::placeholders::_1);
    
    BENCHMARK("Cos Series 1. - 1") {
        return coss(1.);
    };

    BENCHMARK("Cos Std 1. - 1") {
        if constexpr (std::is_same<float, TestType>::value) {
            return std::cosf(1.);
        }
        else {
            return std::cos(1.);
        }
    };

    BENCHMARK("Loop Series - 1024") {
        constexpr int nsteps = 1024;
        volatile TestType res = 0.;
        for(int i = 0; i < nsteps; ++i) {
            res += TestType(1.);
        }
    };

    BENCHMARK("Cos Series 1. - 1024") {
        constexpr int nsteps = 1024;
        volatile TestType res = 0.;
        for(int i = 0; i < nsteps; ++i) {
            res += coss(1.);
        }
    };

    BENCHMARK("Cos Std 1. - 1024") {
        constexpr int nsteps = 1024;
        volatile TestType res = 0.;
        for(int i = 0; i < nsteps; ++i) {
            if constexpr (std::is_same<float, TestType>::value) {
                res += std::cosf(1.);
            }
            else {
                res += std::cos(1.);
            }
        }
    };
}
