#include <cstdio>

int n, k;
int main() {
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; i++) {
        if(i%k==0) printf("*");
        else printf("%d",i);
        if(i!=n) printf(" ");
        else printf("\n");
        
    }
    return 0;
}
