#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define INF 2000222
int maks,hasil,a[110000],b[110000],nkoin,nkertas,koin[20],kertas[20];

int main(){
    hasil=INF;
    scanf("%d%d%d", &maks, &nkoin, &nkertas);
    R(i,1,nkoin+1) scanf("%d", &koin[i]);
    R(i,1,nkertas+1) scanf("%d", &kertas[i]);
    R(i,0,maks+1) a[i]=INF,b[i]=INF;
    
    R(i,1,maks+1){
        R(j,1,nkoin+1){
            if( i == koin[j] ) a[i]=1;
            if( i > koin[j] ) a[i]=min(a[i], a[i-koin[j]]+1);
        }
        R(j,1,nkertas+1){
            if( i == kertas[j] ) b[i]=1;
            if( i > kertas[j] ) b[i]=min(b[i], b[i-kertas[j]]+1);
        }
    }

    R(i,1,maks+1){
        if(a[i]%2==0 and (a[i]!=INF and b[maks-i]!=INF) ) hasil=min(hasil,a[i]+b[maks-i]);
        //else if(a[i]%2==0 and a[i]!=INF and b[maks-i]==INF) hasil=min(hasil,a[i]);
        //else if(a[i]%2==0 and a[i]==INF and b[maks-i]!=INF) hasil=min(hasil,b[maks-i]);
    }
    
    if(a[maks]%2==0) hasil=min(hasil,a[maks]);
    hasil=min(hasil,b[maks]);
    printf("%d\n", hasil==INF? -1 : hasil);
    scanf("\n");
    return 0;
}
