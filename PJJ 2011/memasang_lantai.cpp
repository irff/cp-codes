#include <cstdio>
using namespace std;

int n, a[2000];
int main() {
    scanf("%d", &n);
    a[1]=1;
    a[2]=1;
    a[3]=2;
    for(int i=4; i<=n; i++) a[i] = (a[i-1]+a[i-3])%1000000;
    printf("%d\n", a[n]);
    return 0;
}
