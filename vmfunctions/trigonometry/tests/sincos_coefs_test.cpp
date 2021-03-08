#ifndef CATCH_CONFIG_MAIN
    #define CATCH_CONFIG_MAIN
#endif

#include "catch2/catch.hpp"

#include "vmfunctions/tests/tests_common.hpp"
#include "vmfunctions/trigonometry/cos_coefs.hpp"
#include "vmfunctions/trigonometry/sin_coefs.hpp"

using test_types = std::tuple<
                    std::tuple<int, float>,
                    std::tuple<int, double>,
                    std::tuple<long, float>,
                    std::tuple<long, double>>;

TEMPLATE_LIST_TEST_CASE("cos coeffients", "[cos][coefs]", test_types) {
    using namespace vmfunctions::trigonometry;
    using I = std::tuple_element_t<0, TestType>;
    using F = std::tuple_element_t<1, TestType>;
    const auto ccoef = std::bind(coscoef<F, I>, std::placeholders::_1);
    ALMOST_EQUAL(ccoef(0), F(1));
    ALMOST_EQUAL(ccoef(1), F(0));
    ALMOST_EQUAL(ccoef(2), F(-1. / 2.));
    ALMOST_EQUAL(ccoef(3), F(0));
    ALMOST_EQUAL(ccoef(4), F(1. / 24.));
    ALMOST_EQUAL(ccoef(5), F(0));
    ALMOST_EQUAL(ccoef(6), F(-1. / 720.));
}

TEMPLATE_LIST_TEST_CASE("sin coeffients", "[sin][coefs]", test_types) {
    using namespace vmfunctions::trigonometry;
    using I = std::tuple_element_t<0, TestType>;
    using F = std::tuple_element_t<1, TestType>;
    const auto scoef = std::bind(sincoef<F, I>, std::placeholders::_1);
    ALMOST_EQUAL(scoef(0), F(0.));
    ALMOST_EQUAL(scoef(1), F(1.));
    ALMOST_EQUAL(scoef(2), F(0.));
    ALMOST_EQUAL(scoef(3), F(-1. / 6.));
    ALMOST_EQUAL(scoef(4), F(0.));
    ALMOST_EQUAL(scoef(5), F(1. / 120.));
    ALMOST_EQUAL(scoef(6), F(0.));
}
