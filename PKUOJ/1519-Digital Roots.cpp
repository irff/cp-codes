#include <cstdio>

long long n;
int main(){
    scanf("%lld", &n);
    while(n!=0){
        printf("%d\n", n%9!=0?n%9:9);
        scanf("%lld", &n);
    }
}
