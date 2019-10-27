
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <cinttypes>
#include "linker_array.h"

LINKER_ARRAY_BEGIN("registryTest") int registryTestBegin;
LINKER_ARRAY_END("registryTest") int registryTestEnd;

LINKER_ARRAY_ENTRY("registryTest") int a = 124;
LINKER_ARRAY_ENTRY("registryTest") int b = 456;
LINKER_ARRAY_ENTRY("registryTest") int c = 789;

int main(int argc, char** argv) {
    printf("registryTestBegin: %p\n", &registryTestBegin);
    printf("registryTestEnd: %p\n", &registryTestEnd);

    int i = 0;
    const int* const rb = &registryTestBegin;
    const int* const re = &registryTestEnd;
    printf("rb=%p\n", rb);
    printf("re=%p\n", re);
    printf("rn %d items\n", (int)(re - rb));
    for (const int* ip = rb; ip != re; ++ip) {
        if (ip == re) {
	    printf("WTF\n");
	}
	printf("  [i=%3d][ip=%p]: %p\n", i++, ip, *ip);
	printf("          re=%p\n", re);
	printf("          rb=%p\n", rb);
    }
    
    printf("a: %p\n", &a);
    printf("b: %p\n", &b);
    printf("c: %p\n", &c);
    return 0;
}
