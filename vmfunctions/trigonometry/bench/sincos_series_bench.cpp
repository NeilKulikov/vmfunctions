#ifndef CATCH_CONFIG_MAIN
    #define CATCH_CONFIG_MAIN
#endif

#ifndef CATCH_CONFIG_ENABLE_BENCHMARKING
    #define CATCH_CONFIG_ENABLE_BENCHMARKING
#endif

#include "catch2/catch.hpp"

#include <cmath>
#include <vector>
#include <algorithm>
#include <type_traits>

#include "vmfunctions/trigonometry/sin_series.hpp"

using test_types = std::tuple<float, double>;

#define SINS vmfunctions::trigonometry::sins<TestType>

TEMPLATE_LIST_TEST_CASE("sin series", "[sin][series]", test_types) {   
    BENCHMARK("Sin Series 1. - 1") {
        return SINS(1.);
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
            res += SINS(1.);
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

TEMPLATE_LIST_TEST_CASE("sin series transform", "[sin][series][wise]", test_types) {
    constexpr int nsteps = 1024;
    std::vector<TestType> inp(nsteps, TestType(1));
    std::vector<TestType> out(nsteps, TestType(1));
    
    BENCHMARK("Sin Series - 1024") {
        std::transform(inp.cbegin(), inp.cend(), out.begin(), SINS);
    };

    BENCHMARK("Sin Series Direct - 1024") {
        for(int i = 0; i < nsteps; ++i) {
            out[i] = SINS(inp[i]);
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

#include "vmfunctions/trigonometry/cos_series.hpp"

#define COSS vmfunctions::trigonometry::coss<TestType>

TEMPLATE_LIST_TEST_CASE("cos series", "[cos][series]", test_types) {    
    BENCHMARK("Cos Series 1. - 1") {
        return COSS(1.);
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
            res += COSS(1.);
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

TEMPLATE_LIST_TEST_CASE("cos series transform", "[cos][series][wise]", test_types) {
    constexpr int nsteps = 1024;
    std::vector<TestType> inp(nsteps, TestType(1));
    std::vector<TestType> out(nsteps, TestType(1));
    
    BENCHMARK("Cos Series - 1024") {
        std::transform(inp.cbegin(), inp.cend(), out.begin(), COSS);
    };

    BENCHMARK("Cos Series Direct - 1024") {
        for(int i = 0; i < nsteps; ++i) {
            out[i] = COSS(inp[i]);
        }
    };

    BENCHMARK("Cos Std - 1024") {
        constexpr auto cos = [] (auto x) { 
                if constexpr (std::is_same<float, TestType>::value) {
                    return std::cosf(1.);
                }
                else {
                    return std::cos(1.);
                }
            };
        std::transform(inp.cbegin(), inp.cend(), out.begin(), cos);
    };

    BENCHMARK("Cos Std Direct - 1024") {
        for(int i = 0; i < nsteps; ++i) {
            if constexpr (std::is_same<float, TestType>::value) {
                out[i] = std::cosf(inp[i]);
            }
            else {
                out[i] = std::cos(inp[i]);
            }
        }
    };
}
