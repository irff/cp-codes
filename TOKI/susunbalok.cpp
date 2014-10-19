#include <cstdio>
#include <bitset>
using namespace std;

int num,teskes;
long long nkoin,koin[300000];
bitset<10000> bs;
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        bs.reset();
        bs[0]=1;
        scanf("%lld%d", &nkoin, &num);
        for(long long i=0; i<nkoin; i++){
            scanf("%lld", &koin[i]);
            if(!bs[num]){
              for(int j=num; j-koin[i]>=0; j--){
                if(bs[j-koin[i]]) bs[j]=1;
                if(bs[num]) break;
              }
            }
        }
        printf("%s\n", bs[num]?"YA":"TIDAK");
    }
    return 0;
}
