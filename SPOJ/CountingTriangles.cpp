#include <cstdio>

int teskes;
long long n,hasil;
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        scanf("%lld", &n);
        hasil=0LL;
        if(n%2LL==1LL) {
            hasil=((2LL*n*n)+(3LL*n-1LL))/2LL;
            hasil=hasil*(n+1LL)/4LL;
        }
        else hasil=n*(n+2LL)*(2LL*n+1LL)/8LL;
        printf("%lld\n", hasil);
    }

}

