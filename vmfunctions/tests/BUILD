load("@rules_cc//cc:defs.bzl", "cc_test")

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
    srcs = ["common_test.cpp"],
    deps = [
        ":common",
        "//vmfunctions:root",
        "@catch2//:catch2",
    ],
    visibility = ["//visibility:public"],
)