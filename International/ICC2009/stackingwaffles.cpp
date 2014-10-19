#include <cstdio>
#include <algorithm>
using namespace std;
#define x first
#define y second
typedef pair<int,int> PII;

int n,maks,dp[2012];
PII waffle[2012];
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d", &waffle[i].x, &waffle[i].y);
    }
    sort(waffle,waffle+n);
    dp[0]=1; maks=1;
    for(int i=1; i<n; i++) {
        int j=i-1;
        while(j>0 and (waffle[i].x <= waffle[j].x or waffle[i].y <= waffle[j].y) ) {
            j--;
        }
        dp[i]=dp[j]+1;
        maks=max(maks,dp[i]);
        printf("->%d %d %d\n", i, dp[i], j);
    }
    printf("%d\n", maks);

    return 0;
}
