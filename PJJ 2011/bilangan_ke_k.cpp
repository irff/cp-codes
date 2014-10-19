#include <cstdio>
#include <functional>
#include <algorithm>
using namespace std;

int n, k, a[100200];
int main() {
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    sort(a, a+n, greater<int>());
    printf("%d\n", a[k-1]);
    return 0;
}
