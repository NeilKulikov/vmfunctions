load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_test(
    name = "coefs-test",
    srcs = glob(["*_coefs_test.cpp"]),
    deps = [
        "//vmfunctions/tests:common",
        "//vmfunctions/trigonometry:coefs",
        "@catch2//:catch2",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "residue",
    srcs = [],
    hdrs = ['residue.hpp'],
    deps = [
        "//vmfunctions:common",
        "@catch2//:catch2",
    ],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "residue-test",
    srcs = ["residue_test.cpp"],
    deps = [
        "//vmfunctions/tests:common",
        "@catch2//:catch2",
        ":residue",
    ],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "series-test",
    srcs = glob(["*_series_test.cpp"]),
    deps = [
        ":residue",
        "//vmfunctions/tests:common",
        "//vmfunctions/trigonometry:series",
        "@catch2//:catch2",
    ],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "unbalanced-test",
    srcs = glob(["*_unbalanced_test.cpp"]),
    deps = [
        "//vmfunctions/trigonometry:unbalanced",
        "//vmfunctions/tests:common",
        "@catch2//:catch2",
    ],
    visibility = ["//visibility:public"],
)
