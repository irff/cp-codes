#include <cstdio>
#include <algorithm>
using namespace std;

int n, maks;
int a[100111], dp[2000];
int main() {
    scanf("%d%d", &n, &maks);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=1; i<=1200; i++) dp[i] = 2000111222;
    for(int i=0; i<n; i++) {
        for(int j=maks; j>=a[i]; j--) dp[j] = min(dp[j], dp[j-a[i]]+1);
    }
    printf("%d\n", dp[maks]);
    return  0;
}
