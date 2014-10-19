#include <cstdio>

long long a[20];
int n;
int main(){
    a[0]=2;
    for(int i=1; i<=15; i++) a[i]=a[i-1]+a[i-1]-1;
    scanf("%d", &n);
    printf("%lld\n", a[n]*a[n]);
    scanf("\n");
}
