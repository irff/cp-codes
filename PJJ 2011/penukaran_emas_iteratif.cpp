#include <algorithm>
#include <cstdio>
using namespace std;

int n, a[12000];
int main() {
    scanf("%d", &n);
    for(int i=2; i<=n; i++) a[i] = max(i, a[i/2]+a[i/3]+a[i/4]);
    printf("%d\n", a[n]);
    return 0;
}
