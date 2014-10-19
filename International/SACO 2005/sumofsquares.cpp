#include <cstdio>

int hasil,a,b;
int main() {
    scanf("%d%d", &a, &b);
    for(int i=a; i<=b; i++) hasil+=(i*i);
    printf("%d\n", hasil);
    return 0;
}
