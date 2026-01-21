workspace(name = "jzz")


load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository", "new_git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")


http_archive(
    name = "zstd_1.5.7",
    urls = ["https://github.com/facebook/zstd/releases/download/v1.5.7/zstd-1.5.7.tar.gz"],
    sha256 = "eb33e51f49a15e023950cd7825ca74a4a2b43db8354825ac24fc1b7ee09e6fa3",
    strip_prefix = "zstd-1.5.7/lib",
    build_file='//:net_zstd.BUILD'
)

http_archive(
    name = "zstd_1.4.4",
    urls = ["https://github.com/facebook/zstd/releases/download/v1.4.4/zstd-1.4.4.tar.gz"],
    sha256 = "59ef70ebb757ffe74a7b3fe9c305e2ba3350021a918d168a046c6300aeea9315",
    strip_prefix = "zstd-1.4.4/lib",
    build_file='//:net_zstd.BUILD'
)

http_archive(
    name = "zstd_1.3.8",
    urls = ["https://github.com/facebook/zstd/releases/download/v1.3.8/zstd-1.3.8.tar.gz"],
    sha256 = "293fa004dfacfbe90b42660c474920ff27093e3fb6c99f7b76e6083b21d6d48e",
    strip_prefix = "zstd-1.3.8/lib",
    build_file='//:net_zstd.BUILD'
)
