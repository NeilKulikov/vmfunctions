#include "catch2/catch.hpp"

#include "vmfunctions/type_manipulations.hpp"

using types = std::tuple<
                std::tuple<std::int32_t, float>,
                std::tuple<std::int64_t, double> >;

TEMPLATE_LIST_TEST_CASE("sign flip via xor", "[xor]", types) {
    using namespace vmfunctions::common;
    using I = std::tuple_element_t<0, TestType>;
    using F = std::tuple_element_t<1, TestType>;
    constexpr int shift = sizeof(F);
    constexpr I mask = I(1) << (8 * shift - 1);
    if constexpr (std::is_same<F, float>::value) {
        REQUIRE(mask == std::int32_t(0x80000000));
    } else {
        REQUIRE(mask == std::int64_t(0x8000000000000000));
    }
    REQUIRE(XOR(F(-0.1), mask) == F(0.1));
    REQUIRE(XOR(F(0.1), mask) == F(-0.1));
    REQUIRE(XOR(F(-512.3), mask) == F(512.3));
    REQUIRE(XOR(F(512.3), mask) == F(-512.3));
}