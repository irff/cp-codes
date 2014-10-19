#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes, n, k, p;
int dp[100][100];
int main() {
    R(i,0,71) {
        R(j,0,i+1) {
            if(j==0 or j==i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
    }
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d%d%d", &k, &n, &p);
        printf("%d\n", dp[n+k-(k*p)-1][k-1]);
    }
    return 0;
}
