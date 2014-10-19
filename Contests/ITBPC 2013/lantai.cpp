#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef long long LLD;
typedef unsigned long long LLU;

int a, b;

LLU dp[1200111];

int main() {
    scanf("%d%d", &a, &b);
    dp[0] = 1;
    R(i,1,a+1) {
        dp[i] = dp[i-1];
        if(b!=1 and i>=b) dp[i]=(LLU)(dp[i] + dp[i-b]);
    }
    printf("%llu\n", dp[a]);
    return 0;
}
