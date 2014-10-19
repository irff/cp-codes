#include <cstdio>

unsigned long long x,y;
int teskes;
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        scanf("%I64u", &x);
        printf("%I64u\n", (x-1)*250+192);
    }
    return 0;
}
