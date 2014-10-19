#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

const int INF = 2000111222;

int maks = 0, k, n, a[60];
int dp[2000111];
int main() {
    scanf("%d%d", &k, &n);
    R(i,0,n) { scanf("%d", &a[i]); maks = max(maks, a[i]); }
    maks*=k;
    R(i,0,maks+2) bit[i] = INF;
    bit[0] = 0;
    R(i,0,n) {
        R(j,a[i],maks+1) {
            bit[j] = min(bit[j], bit[j - a[i] ]+1);
        }
    }
    R(i,0,maks+2) {
        if(bit[i]==INF) {
            printf("%d\n", i-1);
            break;
        }
    }
    return 0;
}
