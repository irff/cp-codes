#include <cstdio>
#include <algorithm>
using namespace std;

int n;
long long cost = 0, a[6000];
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    cost = 0;
    sort(a, a+n);
    for(int i=1; i<n; i++) {
        a[i] = (long long) a[i-1]+a[i];
        cost+=a[i];
    }
    printf("%lld\n", cost);
  
    return 0;
}
