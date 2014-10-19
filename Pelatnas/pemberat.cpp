#include <cstdio>

long long x=1,bebek,kucing,selisih;
int n=0;
int main() {
    scanf("%lld%lld", &bebek, &kucing);
    selisih=kucing-bebek;
    while(x <= selisih) x*=2,n++;
    n--;
    while(selisih > 0 and n>=0) {
        if(selisih-(1<<n)>=0) {
            printf("%lld\n", (long long)(1<<n));
            selisih-=(1<<n);
        }
        n--;
    }

}
