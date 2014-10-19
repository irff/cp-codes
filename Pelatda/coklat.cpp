#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef long long LLD;

LLD x, can, n;

int main() {
    scanf("%lld", &x);
    x*=2;
    can = (LLD)sqrt((double)x);
    for(LLD i = can-1; i<=can+1; i++) {
        if(i*(i+1)>x) { printf("%d\n", i); break; }
    }
    return 0;
}
