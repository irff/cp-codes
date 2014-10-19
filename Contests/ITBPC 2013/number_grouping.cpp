#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef long long LLD;
typedef unsigned long long LLU;

LLD n, m, result = 0;
int main() {
    scanf("%lld%lld", &n, &m);
    while(m>1) {
        result = result + m*n;
        m--,n--;
        if(n==0) break;
    }
    LLD total = 0;
    if(n > 0) {
        total = (n * (n+1))/2;
        total = (LLD)ceil((double)total/n);
    }
    printf("%lld\n", result+total);
    return 0;
}
