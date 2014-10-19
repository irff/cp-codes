#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef long long LLD;
typedef unsigned long long LLU;

LLD a, b, n;
int main() {
    scanf("%lld%lld", &a, &b);
    n = 3*a + 3*b - 10;
    printf("%lld\n", n);
    return 0;
}
