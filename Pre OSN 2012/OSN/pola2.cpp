#include <cstdio>

int n, ctr=0;
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) printf("%d", (ctr++)%10);
        printf("\n");
    }
    return 0;
}
