#include <cstdio>
#include <algorithm>
using std:: min;
#define R(i,_a,_b) for(int i=int(_a),c=int(_b);i<c;i++)

int n,teskes,plat[15];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        n=0;
        for(int i=0; i<10; i++) scanf("%d", &plat[i]);
        plat[6]=min(plat[6],plat[9]);
        plat[9]=min(plat[6],plat[9]);
        n=plat[0]+plat[1]+plat[8]+plat[6]*2;
        if(n==0) printf("-1");
        else {
            R(i,0,plat[9]) printf("9");
            if(plat[8]%2==0) R(i,0,plat[8]/2) printf("8");
            if(plat[1]%2==0) R(i,0,plat[1]/2) printf("1");
            if(plat[0]%2==0) R(i,0,plat[0]/2) printf("0");
            if(plat[8]%2==1) R(i,0,plat[8]) printf("8");
            else if(plat[1]%2==1) R(i,0,plat[1]) printf("1");
            else if(plat[0]%2==1) R(i,0,plat[0]) printf("0");
            if(plat[8]%2==0) R(i,0,plat[8]/2) printf("8");
            if(plat[1]%2==0) R(i,0,plat[1]/2) printf("1");
            if(plat[0]%2==0) R(i,0,plat[0]/2) printf("0");
            R(i,0,plat[6]) printf("6");
        }
        printf("\n");
        
    }
    return 0;
}
