#include <cstdio>

int main() {
    int n; scanf("%d", &n);
    if(n<4) printf("NO\n");
    else printf("%s\n", n%2?"NO":"YES");
}
