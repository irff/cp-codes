#include <cstdio>
#include <cmath>

int n;
long long akar,num;

int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%lld", &num);
        akar=sqrt(num);
        if(akar*akar==num) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
