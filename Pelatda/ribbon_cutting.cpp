#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

const int INF = 2000111222;

int n, c[5];
int dp[5000];
int main() {
    scanf("%d%d%d%d", &n, &c[0], &c[1], &c[2], &c[3]);
    R(i,0,n+1) dp[i] = -INF;
    dp[0] = 0;
    R(i,1,n+1) {
        R(j,0,3) {
            if(i-c[j]>=0) {
                dp[i] = max(dp[i], dp[i-c[j]]+1);
            }
        }
    }
    R(i,0,n+1) printf("%d %d\n", i, dp[i]);
    return 0;
}
