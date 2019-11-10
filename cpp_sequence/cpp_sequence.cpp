
#define CAT_(a,b) a ## b
#define CAT(a, b) CAT_(a, b)

#define S0 _
#define S1 X

#define DECADE(F, m, ...) \
    F(m(0),m(1),m(2),m(3),m(4),m(5),m(6),m(7),m(8),m(9))

#define DECADE0(F,...) DECADE(F, __VA_ARGS__)
#define DECADE1(F,...) DECADE(F, DECADE0(F,__VA_ARGS__))
#define DECADE2(F,...) DECADE(F, DECADE1(F,__VA_ARGS__))

#define E2(F,pre) DECADE2(F,pre)

struct Dec { int x; };
Dec decs[] = {

#define M(...) Dec(__VA_ARGS__)
  E2(M,),

};

int main() {
    return 0;
}
