#include <cstdio>

int n,a,b;
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d%d", &a,&b);
    printf("%d\n", n*(n-1)*(n-2)/6);
    return 0;
}
