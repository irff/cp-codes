#include <cstdio>

int teskes,n;
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        scanf("%d", &n);
        int x=0;
        while(n/5>0) x+=n/5,n/=5;
        printf("%d\n", x);
    }

}
