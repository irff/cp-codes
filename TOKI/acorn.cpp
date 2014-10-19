#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int tree, h, lompat, teskes;

int dp[2010][2010], ans[2010][2010];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d%d%d", &tree, &h, &lompat);
        R(i,0,tree) {
            int n, x;
            scanf("%d", &n);
            R(j,0,n) { scanf("%d", &x); dp[x][i]++; }
        }
        R(i,1,h+1) {
            int maks = 0;
            if(i>=lompat) R(j,0,tree) maks=max(maks, dp[i-lompat][j]);
            R(j,0,tree) {
                if(i>=lompat){
                    dp[i][j]+=max(dp[i-1][j], maks);
                } else dp[i][j]+=dp[i-1][j];
            }
        }
        int maks = 0;
        R(i,0,tree) maks = max(maks, dp[h][i]);
        R(i,0,h+2) R(j,0,tree+2) dp[i][j] = 0;
        printf("%d\n", maks);
    }
    scanf("%d", &teskes);
    return 0;
}
