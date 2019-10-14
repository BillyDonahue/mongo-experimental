
#include <inttypes.h>
#include <stddef.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <thread>

void sigAltStackInstall(void* buf, size_t bufSize) {
    fprintf(stderr, "installing sigaltstack= @%p[%#zx]\n", buf, bufSize);
    stack_t ss;
    ss.ss_sp = buf;
    ss.ss_size = bufSize;
    ss.ss_flags = 0;
    if (int r = sigaltstack(&ss, nullptr); r < 0) {
        perror("sigaltstack");
    }
}

void sigAltStackUninstall() {
    stack_t ss;
    ss.ss_sp = 0;
    ss.ss_size = 0;
    ss.ss_flags = SS_DISABLE;
    if (int r = sigaltstack(&ss, nullptr); r < 0) {
        perror("sigaltstack");
    }
}

int main(int argc, char** argv) {
    const size_t bufSize = size_t{1} << 20;  // 1 MiB
    unsigned char* buf = (unsigned char*)malloc(bufSize);
    {
        std::thread thr([&] {
            sigAltStackInstall(buf, bufSize);
            // sigAltStackUninstall();
        });
        thr.join();
    }
    free(buf);
}
