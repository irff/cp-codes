#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;
LLD dp[70][70][2];

LLD rek(int n, int s, int last) {
    if(n==0 and s==0) return dp[n][s][last] = 1;
    if(s > n or n < 0 or s < 0) return 0;
    
    if(dp[n][s][last]!=-1) return dp[n][s][last];
    return dp[n][s][last] = rek(n-1,s-!last,0) + rek(n-1, s, 1);
}

int main() {
    R(i,0,70) R(j,0,70) dp[i][j][0] = dp[i][j][1] = -1;
    int a, b;
    while(scanf("%d%d", &a, &b) and a>0) {
        printf("%lld\n", rek(a,b,0));
    }
    return 0;
}
