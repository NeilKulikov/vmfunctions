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

#define SINU vmfunctions::trigonometry::sinu<TestType>

TEMPLATE_LIST_TEST_CASE("sin unbalanced", "[sin][unbalanced]", test_types) {
    BENCHMARK("Sin Unbalanced 1. - 1") {
        return SINU(1.);
    };

    BENCHMARK("Sin Std 1. - 1") {
        if constexpr (std::is_same<float, TestType>::value) {
            return std::sinf(1.);
        }
        else {
            return std::sin(1.);
        }
    };

    BENCHMARK("Loop Unbalanced - 1024") {
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
            res += SINU(1.);
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

TEMPLATE_LIST_TEST_CASE("sin ynbalanced transform", "[sin][unbalanced][wise]", test_types) {
    constexpr int nsteps = 1024;
    std::vector<TestType> inp(nsteps, TestType(1));
    std::vector<TestType> out(nsteps, TestType(1));
    
    BENCHMARK("Sin Unbalanced - 1024") {
        std::transform(inp.cbegin(), inp.cend(), out.begin(), SINU);
    };

    BENCHMARK("Sin Unbalanced Direct - 1024") {
        for(int i = 0; i < nsteps; ++i) {
            out[i] = SINU(inp[i]);
        }
    };

    BENCHMARK("Sin Std - 1024") {
        constexpr auto sin = [] (auto x) { 
                if constexpr (std::is_same<float, TestType>::value) {
                    return std::sinf(1.);
                }
                else {
                    return std::sin(1.);
                }
            };
        std::transform(inp.cbegin(), inp.cend(), out.begin(), sin);
    };

    BENCHMARK("Sin Std Direct - 1024") {
        for(int i = 0; i < nsteps; ++i) {
            if constexpr (std::is_same<float, TestType>::value) {
                out[i] = std::sinf(inp[i]);
            }
            else {
                out[i] = std::sin(inp[i]);
            }
        }
    };
}
