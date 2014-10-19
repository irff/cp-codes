#include <cstdio>


int teskes,n,now;
bool arah;

bool cektujuh(int num) {
    if(num%7==0) return 1;
    while(num!=0) {
        if(num%10==7) return 1;
        num/=10;
    }
    return 0;
}

int main () {
    scanf("%d", &teskes);
    while(teskes--) {
        arah=1,now=0;
        scanf("%d", &n);
        for(int i=1; i<=n; i++) {
            if(arah==1) {
                now++; 
                if(now==n+1) now=1;
            } else {
                now--;
                if(now==0) now=n;
            }
            if(cektujuh(i)==1) {
                arah=!arah;
            }
        }
        printf("%d\n", now);
    }
    return 0;
}
