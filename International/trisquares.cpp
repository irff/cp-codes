#include <cstdio>

int n;

int main() {
    scanf("%d", &n);
    int x=n/2;
    for(int j=0; j<x; j++) printf(" "); printf("x");
    printf("\n");
    for(int i=1; i<x; i++){
        for(int j=0; j<x-i; j++) printf(" ");
        printf("x");
        for(int j=0; j<2*i-1; j++) printf(" ");
        printf("x");
        printf("\n");        
    }
    for(int i=0; i<n; i++) printf("x");
    printf("\n");
    for(int i=0; i<n-2; i++) {
        printf("x");
        for(int j=0; j<n-2; j++) printf(" ");
        printf("x\n");
    }
    for(int i=0; i<n; i++) printf("x");
    printf("\n");
    
    return 0;
}
