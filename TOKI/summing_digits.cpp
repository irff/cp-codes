#include <cstdio>

int n;
int main() {
    while(scanf("%d", &n), n!=0) {
        printf("%d\n", (n-1)%9+1);
    }
    return 0;
}
