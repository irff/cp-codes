#include <cstdio>

int n, sum=0;
int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) { sum+=i; printf("%d\n", sum); }
    return 0;
}
