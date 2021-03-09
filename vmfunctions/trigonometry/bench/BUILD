load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "series-bench",
    srcs = glob(["*_series_bench.cpp"]),
    deps = [
        "//vmfunctions/trigonometry:series",
        "@catch2//:catch2",
    ],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "unbalanced-bench",
    srcs = glob(["*_unbalanced_bench.cpp"]),
    deps = [
        "//vmfunctions/trigonometry:unbalanced",
        "@catch2//:catch2",
    ],
    visibility = ["//visibility:public"],
)