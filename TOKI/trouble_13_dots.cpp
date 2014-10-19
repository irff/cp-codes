#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

int budget, barang;
int v[120],w[120],dp[30111];
int main() {
    while(scanf("%d%d", &budget, &barang) > 0) {
        memset(dp, 0, sizeof dp);
        R(i,0,barang) {
            scanf("%d%d", &w[i], &v[i]);
        }
        if(budget > 2000) budget+=200;
        R(i,0,barang) {
            RV(j,budget,w[i]) {
                if(j==w[i]) dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
                else if(dp[j-w[i]]!=0 and j > w[i]) dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
            }
        }
        int ans = 0;
        RV(i,budget,0) {
            ans = max(ans, dp[i]);
        }
        //printf("%d\n", dp[budget]);
        printf("%d\n", ans);
    }

    return 0;
}
