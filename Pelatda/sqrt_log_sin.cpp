#include <cstdio>
#include <cstdlib>
#include <cmath>

#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

const int MOD = 1000000;

long long a[1000111];
int n;

int main() {
    a[0] = 1;
    for(int i=1; i<=1000002; i++) {
        long long x, y, z;
        x = trunc(i-sqrt(i));
        y = trunc(log(i)/log(exp(1)));
        z = trunc(i*sin(i)*sin(i));
        a[i] = (a[x]+a[y]+a[z])%MOD;
    }
    scanf("%d", &n);
    while(n!=-1) {
        printf("%d\n", a[n]);
        scanf("%d", &n);
    }
    return 0;
}
