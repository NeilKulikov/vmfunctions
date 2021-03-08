load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "coefs",
    srcs = [],
    hdrs = glob(["*_coefs.hpp"]),
    deps = ["//vmfunctions:common"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "series",
    srcs = [],
    hdrs = glob(["*_series.hpp"]),
    deps = [":coefs"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "unbalanced",
    srcs = [],
    hdrs = glob(["*_unbalanced.hpp"]),
    deps = [
                "//vmfunctions:consts",
                "//vmfunctions:common",
                ":series", 
            ],
    visibility = ["//visibility:public"],
)