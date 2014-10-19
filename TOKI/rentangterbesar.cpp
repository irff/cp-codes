#include <cstdio>
#include <algorithm>
using namespace std;

long long maks,nkoin,koin[100001];
int teskes;
int main(){
    scanf("%lld", &teskes);
    while(teskes--){
        scanf("%lld", &nkoin);
        for(long long i=0; i<nkoin; i++) scanf("%lld", &koin[i]);
        sort(koin,koin+nkoin);
        maks=0;
        for(long long i=0; i<nkoin; i++) {
            if(koin[i] <= maks+1) maks=maks+koin[i];
        }
        printf("%lld\n", maks);
    
    }

    return 0;
}
