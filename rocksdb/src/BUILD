package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "stub_os_l",
    srcs = glob(["*cpp"]),
    hdrs = glob(["*.h"]),
    deps = [
        "@com_github_facebook_rocksdb//:rocksdb",
        "@com_github_facebookresearch_faiss//:faiss",
        "@boost//:asio",

    ],
  copts = ["-std=c++2a"],
)

cc_binary(
    name = "stub_os",
    srcs = glob(["*cpp"]),
    deps = [
        "@com_github_facebook_rocksdb//:rocksdb",
        "@com_github_facebookresearch_faiss//:faiss",
        "@boost//:asio",

    ],
  copts = ["-std=c++2a"],
)
