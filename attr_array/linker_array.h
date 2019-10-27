
#define LINKER_ARRAY_SECTION(x, part) ".mongodb.table." x "." part
#define LINKER_ARRAY_ENTRY(x) __attribute__((section(LINKER_ARRAY_SECTION(x, "data"))))
#define LINKER_ARRAY_BEGIN(x) __attribute__((section(LINKER_ARRAY_SECTION(x, "begin"))))
#define LINKER_ARRAY_END(x)   __attribute__((section(LINKER_ARRAY_SECTION(x, "finish"))))
