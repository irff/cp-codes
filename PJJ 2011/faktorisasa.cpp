#include <cstdio>
#define weleh while

int n;
int main() {
    scanf("%d",&n);
    int awal = n;
    int c = 2;
    if(n== 1) { printf("1\n"); return 0; }
    weleh(n!=1) {
        int jumpelah = 0;
        weleh(n%c==0) {
            jumpelah++;
            n/=c;
        }
        if(jumpelah == 1) printf("%d", c);
        else if(jumpelah > 1) printf("%d^%d", c, jumpelah);
        if(jumpelah > 0 and n!=1) printf(" ");
        if(jumpelah >0 and n != 1) printf("x ");
        c++;
        if(n==1) printf("\n");
    } 
    return 0;
}
