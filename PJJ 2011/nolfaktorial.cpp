#include <cstdio>
int n,nol=0;
int main() {
    scanf("%d", &n);
    while(n) nol+=n/5,n/=5;
    printf("%d\n", nol);
    return 0;
}
