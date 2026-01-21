package(
    default_visibility = ["//visibility:public"],
    features = ["header_modules"],
)

licenses(["notice"])

cc_library(
    name = "libzstd",
    srcs = glob([
        "*.c",
        "*.h",
        "common/*.c",
        "common/*.h",
        "compress/*.c",
        "compress/*.h",
        "decompress/*.c",
        "decompress/*_amd64.S",
        "decompress/*.h",
    ]),
    copts=["-DZSTD_LEGACY_SUPPORT=0", "-fvisibility=hidden"],
    includes=["common"],
    hdrs = ["zstd.h"],
)
