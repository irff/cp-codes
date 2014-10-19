#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);j--)

int n,maks,dp[10200],w[10200],v[10200];
int main() {
    scanf("%d%d", &n,&maks);
    R(i,1,n+1) scanf("%d%d", &w[i],&v[i]);
    R(i,1,n+1) {
        RV(j,maks,w[i]) {
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    printf("%d\n", dp[maks]);
    return 0;
}
