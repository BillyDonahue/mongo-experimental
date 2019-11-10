
#define CAT_(a,b) a ## b
#define CAT(a, b) CAT_(a, b)

#define S0 _
#define S1 X

// Challenge: Make a tuple of digits that can be applied to a function macro.
#define D0(a,b,c,d) Dec(a,b,c,d),
#define D1(a,b,c) \
    D0(a,b,c,0) D0(a,b,c,1) D0(a,b,c,2) D0(a,b,c,3) D0(a,b,c,4) \
    D0(a,b,c,5) D0(a,b,c,6) D0(a,b,c,7) D0(a,b,c,8) D0(a,b,c,9)
#define D2(a,b) \
    D1(a,b,0) D1(a,b,1) D1(a,b,2) D1(a,b,3) D1(a,b,4) \
    D1(a,b,5) D1(a,b,6) D1(a,b,7) D1(a,b,8) D1(a,b,9)
#define D3(a) \
    D2(a,0) D2(a,1) D2(a,2) D2(a,3) D2(a,4) D2(a,5) \
    D2(a,6) D2(a,7) D2(a,8) D2(a,9)
#define D4 D3(0) D3(1) D3(2) D3(3) D3(4) D3(5) D3(6) D3(7) D3(8) D3(9) 


struct Dec { int x; };
Dec decs[] = {
  D4
};

int main() {
    return 0;
}
