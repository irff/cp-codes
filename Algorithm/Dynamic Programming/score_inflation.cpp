#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int maks, n;
int point[10111], waktu[10111], dp[10111];
int main() {
    scanf("%d%d", &maks, &n);
    R(i,0,n) scanf("%d%d", &point[i], &waktu[i]);
    R(i,0,n) {
        R(j,waktu[i],maks+1) {
            dp[j] = max(dp[j], dp[j - waktu[i] ]+point[i]);
        }
    }
    printf("%d\n", dp[maks]);
    return 0;
}
