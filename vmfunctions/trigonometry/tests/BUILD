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