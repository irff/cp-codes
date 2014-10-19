#include <cstdio>
#include <functional>
#include <algorithm>
using namespace std;

int va[10200],vb[10200];
int n;
long long hasil;
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &va[i]);
    for(int i=0; i<n; i++) scanf("%d", &vb[i]);
    sort(va,va+n); sort(vb,vb+n,greater<int>());
    for(int i=0; i<n; i++) {
        hasil+=(va[i]*vb[i]);
    }
    printf("%lld\n", hasil);

}
