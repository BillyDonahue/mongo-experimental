#include <iostream>

#define NDIGITS 4

#define PRIMITIVE_CAT(a, b) a ## b
#define CAT(a, b) PRIMITIVE_CAT(a, b)

#define D0(e, ...) e(__VA_ARGS__)
#define D1(...) \
    D0(__VA_ARGS__,0) D0(__VA_ARGS__,1) D0(__VA_ARGS__,2) D0(__VA_ARGS__,3) D0(__VA_ARGS__,4) \
    D0(__VA_ARGS__,5) D0(__VA_ARGS__,6) D0(__VA_ARGS__,7) D0(__VA_ARGS__,8) D0(__VA_ARGS__,9)
#define D2(...) \
    D1(__VA_ARGS__,0) D1(__VA_ARGS__,1) D1(__VA_ARGS__,2) D1(__VA_ARGS__,3) D1(__VA_ARGS__,4) \
    D1(__VA_ARGS__,5) D1(__VA_ARGS__,6) D1(__VA_ARGS__,7) D1(__VA_ARGS__,8) D1(__VA_ARGS__,9)
#define D3(...) \
    D2(__VA_ARGS__,0) D2(__VA_ARGS__,1) D2(__VA_ARGS__,2) D2(__VA_ARGS__,3) D2(__VA_ARGS__,4) \
    D2(__VA_ARGS__,5) D2(__VA_ARGS__,6) D2(__VA_ARGS__,7) D2(__VA_ARGS__,8) D2(__VA_ARGS__,9)
#define D4(...) \
    D3(__VA_ARGS__,0) D3(__VA_ARGS__,1) D3(__VA_ARGS__,2) D3(__VA_ARGS__,3) D3(__VA_ARGS__,4) \
    D3(__VA_ARGS__,5) D3(__VA_ARGS__,6) D3(__VA_ARGS__,7) D3(__VA_ARGS__,8) D3(__VA_ARGS__,9)
#define D5(...) \
    D4(__VA_ARGS__,0) D4(__VA_ARGS__,1) D4(__VA_ARGS__,2) D4(__VA_ARGS__,3) D4(__VA_ARGS__,4) \
    D4(__VA_ARGS__,5) D4(__VA_ARGS__,6) D4(__VA_ARGS__,7) D4(__VA_ARGS__,8) D4(__VA_ARGS__,9)

#define MAKE_OBJ(...) Dec{__VA_ARGS__},

struct Dec { int digits[NDIGITS]; };
constexpr Dec decs[] = {
  CAT(D, NDIGITS) (MAKE_OBJ)
};

int main() {
  for (auto d : decs) {
    std::cout << "(";
    for (auto&& dig : d.digits) {
      std::cout << dig;
    }
    std::cout << ")";
  }
  std::cout << "\n";
  return 0;
}
