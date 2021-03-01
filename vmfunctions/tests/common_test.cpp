#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "vmfunctions/common.hpp"
#include "vmfunctions/tests/tests_common.hpp"

using int_types = std::tuple<int, long, unsigned int, unsigned long>;

TEMPLATE_LIST_TEST_CASE("factorials", "[factorial]", int_types) {
    using namespace vmfunctions::common;
    REQUIRE(factorial<TestType>(0) == 1ul);
    REQUIRE(factorial<TestType>(1) == 1ul);
    REQUIRE(factorial<TestType>(2) == 2ul);
    REQUIRE(factorial<TestType>(3) == 6ul);
}

using test_types = std::tuple<
                    std::tuple<int, float>,
                    std::tuple<int, double>,
                    std::tuple<long, float>,
                    std::tuple<long, double>>;

TEMPLATE_LIST_TEST_CASE("reverse factorials", "[rfactorial]", test_types) {
    using namespace vmfunctions::common;
    using I = std::tuple_element_t<0, TestType>;
    using F = std::tuple_element_t<1, TestType>;
    const auto rfact = std::bind(rfactorial<F, I>, std::placeholders::_1);
    CAPTURE(F(1.), rfact(0));
    ALMOST_EQUAL(F(1.), rfact(0));
    CAPTURE(F(1.), rfact(1));
    ALMOST_EQUAL(F(1.), rfact(1));
    CAPTURE(F(1. / 2.), rfact(2));
    ALMOST_EQUAL(F(1. / 2.), rfact(2));
    CAPTURE(F(1. / 6.), rfact(3));
    ALMOST_EQUAL(F(1. / 6.), rfact(3));
}

using fpt_types = std::tuple<float, double>;

TEMPLATE_LIST_TEST_CASE("power functional", "[power]", fpt_types) {
    using namespace vmfunctions::common;
    ALMOST_EQUAL(TestType(1), (power<TestType>(1, 0)));
    ALMOST_EQUAL(TestType(1), (power<TestType>(1, 10)));
    ALMOST_EQUAL(TestType(8), (power<TestType>(2, 3)));
    ALMOST_EQUAL(TestType(32), (power<TestType>(2, 5)));
    ALMOST_EQUAL(TestType(6.25), (power<TestType>(2.5, 2)));
    ALMOST_EQUAL(TestType(39.0625), (power<TestType>(2.5, 4)));
    ALMOST_EQUAL(TestType(1), (power<TestType>(3, 0)));
    ALMOST_EQUAL(TestType(81), (power<TestType>(3, 4)));
}
