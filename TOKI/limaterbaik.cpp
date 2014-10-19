#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAKS 100000

long long a[MAKS];
long long teskes,n,jumlah;
int main(){
    scanf("%lld", &teskes);
    while(teskes--){
        memset(a,0,MAKS);
        jumlah=0;
        scanf("%lld", &n);
        for(int i=0; i<n; i++){
            scanf("%lld", &a[i]);
            a[i]*=-1;
        }
        sort(a,a+n);
        for(int i=0; i<5; i++){
            a[i]*=-1;
            jumlah+=a[i];
        }
        printf("%lld\n", jumlah);
    }
    return 0;
}
