#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

int teskes, n;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d", &n);
        R(i,0,n-1) printf(" ");
        R(i,0,n) printf("*");
        R(i,0,2*(n-1)-1) printf(" ");
        R(i,0,n) printf("*");
        printf("\n");
        RV(i,n-2,1) {
            R(j,0,i) printf(" ");
            printf("*");
            R(j,0,n+2*(n-i-2)) printf(" ");
            printf("*");
            R(j,0,i*2-1) printf(" ");
            printf("*");
            R(j,0,n+2*(n-i-2)) printf(" ");
            printf("*");
            printf("\n");
        }
        printf("*");
        R(i,0,n+(2*(n-2))) printf(" ");
        printf("*");
        R(i,0,n+(2*(n-2))) printf(" ");
        printf("*\n");
        int wakakak = 0;
        R(i,0,10*n*n) {
            if(4*(n-3)+2*n+3-(2*i)<=0) break;
            wakakak = i;
            R(j,0,i+1) printf(" ");
            printf("*");
            R(j,0,4*(n-3)+2*n+3-(2*i)) { printf(" "); }
            printf("*\n");
        }
        R(i,0,wakakak+2) printf(" ");
        printf("*");
        printf("\n");
    }

    return 0;
}
