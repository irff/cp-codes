#include <cstdio>
#include <algorithm>
using namespace std;

pair<int,int> a[120000];
int n;
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d", &a[i].second, &a[i].first);
        a[i].first+=a[i].second;
    }
    sort(a, a+n);
    int dapet = 0, now = 0;
    for(int i=0; i<n; i++) {
        if(a[i].second >= now) {
            dapet++;
            now = a[i].first;
        }
    }
    printf("%d\n", dapet);
    return 0;
}
