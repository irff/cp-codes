#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef pair<int,int> PII;

int n;
int weight, strength;

PII a[6000];
int memo[6002][1002];
int rek(int ke, int berat) {
    if(ke>=n) return 0;
    int ans = 0;
    if(memo[ke][berat]) return memo[ke][berat];
    if(a[ke].second + berat <= a[ke+1].first) ans = rek(ke+1, berat+a[ke].second)+1;
    ans = max(ans, rek(ke+1, berat));
    return memo[ke][berat] = ans;
}

int main() {
    scanf("%d", &n);
    R(i,0,n) {
        scanf("%d%d", &a[i].second, &a[i].first);
        a[i].first-=a[i].second;
    }
    a[n].first = 2000111222;
    sort(a, a+n);
    int ans = rek(0,0);
    printf("%d\n", ans);
    return 0;
}
