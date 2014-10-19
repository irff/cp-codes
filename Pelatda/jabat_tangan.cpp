#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LLD;

int n;
LLD a[60];
int main() {
    a[0] = 1;
    a[2] = 1;
    scanf("%d", &n);
    for(int i=4; i<=n; i+=2) {
        for(int j = i-2; j>=0; j--) {
            a[i] += a[j]*a[i-j-2];
        }
    }
    printf("%lld\n", a[n]);
    return 0;
}
