#include <cstdio>
#include <algorithm>
using namespace std;

pair<int,int> a[200];
int n, ans=0, tadi = 0;
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d%d", &a[i].second, &a[i].first);
    sort(a, a+n);
    for(int i=0; i<n; i++) {
        if(a[i].second >= tadi) {
            tadi = a[i].first;
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
