load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "common",
    srcs = [],
    hdrs = glob(["tests_common.hpp"]),
    deps = [
        "@catch2//:catch2",
    ],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "common-test",
    srcs = glob(["*_test.cpp"]),
    deps = [
        ":common",
        "//vmfunctions:common",
        "@catch2//:catch2",
    ],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "test",
    deps = [
        "common-test",
    ],
    visibility = ["//visibility:public"],
)
