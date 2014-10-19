#include <cstdio>
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
int teskes,nsawah,bar,kol;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d%d%d", &nsawah, &kol, &bar);
        R(i,0,bar) {
            if(i==0 or i==bar-1) {
                R(j,0,nsawah){
                    R(k,0,kol) printf("x");
                    if(j!=nsawah-1) printf(" ");
                }
                printf("\n");
            } else {
                R(j,0,nsawah) {
                    printf("x");
                    R(k,0,kol-2) printf(" ");
                    printf("x");
                    if(j!=nsawah-1) printf(" ");
                }
                printf("\n");
            }
        }
        printf("\n");
    }
    return 0;
}
