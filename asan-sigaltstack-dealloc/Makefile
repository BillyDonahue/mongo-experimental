#TC=/opt/mongodbtoolchain/v3
TC=/usr

CXX=${TC}/bin/clang++
CXXFLAGS=-O2 -std=c++17 -fsanitize=address
LDFLAGS=-lpthread -ldl
# --sanitize=address

# /usr/bin/ccache \
# /opt/mongodbtoolchain/v3/bin/clang++
#  -Woverloaded-virtual -Werror=unused-result -Wpessimizing-move -Wredundant-move -Wno-undefined-var-template -Wno-instantiation-after-specialization
#  -fsized-deallocation 
#  -fno-omit-frame-pointer -fno-strict-aliasing -fasynchronous-unwind-tables
#  -ggdb -pthread
#  -Wall -Wsign-compare -Wno-unknown-pragmas -Winvalid-pch -Werror -O0 -Wno-unused-local-typedefs -Wno-unused-function -Wno-unused-private-field -Wno-deprecated-declarations -Wno-tautological-constant-out-of-range-compare -Wno-tautological-constant-compare -Wno-tautological-unsigned-zero-compare -Wno-tautological-unsigned-enum-zero-compare -Wno-unused-const-variable -Wno-missing-braces -Wno-inconsistent-missing-override -Wno-potentially-evaluated-expression -Wno-unused-lambda-capture -Wno-exceptions
#  -fstack-protector-strong -fsanitize=address -fno-omit-frame-pointer -fno-builtin-memcmp -fdiagnostics-color=always
#  -fPIE
#  -Qunused-arguments
#  -DSAFEINT_USE_INTRINSICS=0 -DPCRE_STATIC -D_XOPEN_SOURCE=700 -D_GNU_SOURCE -DADDRESS_SANITIZER -DBOOST_THREAD_VERSION=5 -DBOOST_THREAD_USES_DATETIME -DBOOST_SYSTEM_NO_DEPRECATED -DBOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS -DBOOST_ENABLE_ASSERT_DEBUG_HANDLER -DBOOST_LOG_NO_SHORTHAND_NAMES -DBOOST_LOG_USE_NATIVE_SYSLOG -DABSL_FORCE_ALIGNED_ACCESS -DBOOST_LOG_DYN_LINK -Isrc/third_party/asio-master/asio/include -Isrc/third_party/SafeInt -Isrc/third_party/pcre-8.42 -Isrc/third_party/fmt/dist/include -Isrc/third_party/boost-1.70.0 -Isrc/third_party/abseil-cpp-master/abseil-cpp -Ibuild/dynamic_clang_ninja -Isrc src/mongo/util/stacktrace_test.cpp -MMD -MF build/dynamic_clang_ninja/mongo/util/stacktrace_test.o.d


asan_test: asan_test.cpp
