#include <cstdio>
using namespace std;

int teskes;
long long awal,akhir,ya,tidak,i;
long long jumlah;
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        i=0;
        jumlah=0;
        scanf("%lld%lld%lld%lld", &awal, &akhir, &ya, &tidak);
        for(i=awal; i<=akhir; i++){
            if( (i % ya == 0) and (i%tidak!=0)) jumlah+=i;
        }
        printf("%lld\n", jumlah);
    }
    
    return 0;
}
