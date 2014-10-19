#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes, n, duit, len[30], a[30][30];
int dp[400][30];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d%d", &duit, &n);
        R(i,0,n) {
            scanf("%d", &len[i]);
            R(j,0,len[i]) {
                scanf("%d", &a[i][j]);
            }
        }
        memset(dp, 0, sizeof dp);
        R(i,0,len[0]) dp[duit-a[0][i]][0] = 1;
        R(i,1,n) {
            R(j,0,duit) {
              if(dp[j][i-1]) {
                R(k,0,len[i]) {
                    if(dp[j-a[i][k]]) {
                        dp[j-a[i][k]][i] = 1;
                    }
                }
              }
            }
        }
        bool nemu = 0;
        R(i,0,duit) {
            if(dp[i][n-1]) {
                printf("%d\n", duit-i);
                nemu = 1;
                break;
            }
        }
        if(!nemu) printf("no solution\n");
    }
    return 0;
}
