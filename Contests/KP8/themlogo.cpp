#include <cstdio>

int teskes,n;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<=i; j++) {
                for(int k=n-1; k>j; k--) printf(" ");
                for(int k=0; k<=j; k++) printf("*");
                printf("\n");
            }
            for(int j=i; j>0; j--) {
                for(int k=n; k>j; k--) printf(" ");
                for(int k=0; k<j; k++) printf("*");
                printf("\n");
            }
        }
        printf("\n");
    }
    return 0;
}
