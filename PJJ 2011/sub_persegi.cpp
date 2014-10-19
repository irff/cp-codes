#include <cstdio>

int n;
int main() {
    scanf("%d", &n);
    int jumplah = 0;
    for(int i=1; i<=n; i++) jumplah += (i*i);
    printf("%d\n", jumplah);
    return 0;
}
