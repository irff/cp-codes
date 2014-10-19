#include <cstdio>

int n,nol;
int main() {
    scanf("%d", &n);
    while(n > 0) { nol+=(n/5); n/=5;}
    printf("%d\n", nol);
    return 0;
}
