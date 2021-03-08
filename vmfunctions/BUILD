load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "common",
    srcs = [],
    hdrs = [
        "common.hpp",
        "type_manipulations.hpp",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "consts",
    srcs = [],
    hdrs = glob(["constants.hpp"]),
    visibility = ["//visibility:public"],
)
