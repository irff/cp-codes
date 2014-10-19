#include <cstdio>

int n,mysterious;
int main() {
    scanf("%d", &n);
    if( (n-1)%3==0) {
        for(int i=0; i<n; i++) {
            for(int j=1; j<n-i; j++) printf(" ");
            if(n!=n-1)printf("*");
            if(i < (n-1)/3*2) {
                for(int j=0; j<(i*2)-1; j++) printf(" ");
            } else if(i==n-1){
                
            } else {
                if(i==(n-1)/3*2) mysterious=((i*2)-2)/2;
                for(int j=0; j<mysterious; j++) printf(" ");
                if(i==(n-1)/3*2) printf("*");
                else {
                    printf("*");
                    for(int j=0; j<(i-(n-1)/3*2)*2-1; j++) printf(" ");
                    printf("*");
                }
                for(int j=0; j<mysterious; j++) printf(" ");
            }
            if(i==n-1) {
                for(int j=0; j<=mysterious; j++) printf("%c", (j%2)?'*':' ');
                for(int j=0; j<(i-(n-1)/3*2)*2-1; j++) printf(" ");
                for(int j=0; j<=mysterious+1; j++) printf("%c", (j%2)?' ':'*');
            } else
            if(i!=0) printf("*");
            printf("\n");
        }
    } else {
        printf("Unable to draw tent of this size!");
        printf("Size must be a multiple of 3 plus 1.");
    }
    scanf("\n");
}
