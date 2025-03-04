package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "stub_os",
    srcs = glob(["*cpp"]),
    hdrs = glob(["*.h"]),
    deps = [
        "@com_github_facebook_rocksdb//:rocksdb",
            "@com_github_facebookresearch_faiss//:faiss",

    ],
  copts = ["-std=c++2a"],
)
