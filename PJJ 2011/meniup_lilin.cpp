#include <cstdio>
#include <functional>
#include <algorithm>
using namespace std;

int n, a[55];
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int dapet = 0;
    for(int i=1; i<=n; i++) {
        sort(a,a+n,greater<int>());
        bool jadi = 1;
        for(int j=0; j<i; j++) if(a[j]==0) { jadi=0; break; }
        if(!jadi) break;
        for(int j=0; j<i; j++) a[j]--;
        dapet++;
    }
    printf("%d", dapet);
    return 0;
}
