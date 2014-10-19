#include <cstdio>

int n;
int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) printf("%d ", i*j);
        printf("\n");
    }
    return 0;
}
