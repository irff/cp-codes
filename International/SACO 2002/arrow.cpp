#include <cstdio>

int n;
int main() {
    printf("Enter X : "); scanf("%d", &n);
    for(int i=0; i<n/2+1; i++){
        for(int j=0; j<2*i+1; j++)
            putchar('@');
        printf("\n");
    }
    for(int i=n/2-1; i>=0; i--) {
        for(int j=0; j<2*i+1; j++)
            putchar('@');
        printf("\n");
    }
    return 0;
}
