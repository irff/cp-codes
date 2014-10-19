#include <cstdio>
#include <functional>
#include <algorithm>
using namespace std;

int n;
long long a[12000], b[12000];
long long num = 0;
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%lld", &a[i]);
    for(int i=0; i<n; i++) scanf("%lld", &b[i]);
    sort(a, a+n);
    sort(b, b+n, greater<long long>());
    
    for(int i=0; i<n; i++) num += (a[i]*b[i]);
    printf("%lld\n", num);
    return 0;
}
