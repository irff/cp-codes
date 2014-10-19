#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)
#define LLD long long

LLD bar,kol,nbatu,m[505][505],data[505][505],a1,a2,b1,b2,maks;

LLD cari(LLD x, LLD y){
    LLD ki=y,ka=y;                         // batas kiri dan kanan
    while(ki>=0 and m[x][ki]) ki--;        // sisi kiri - 1
    while(ka<=kol+1 and m[x][ka]) ka++;    // sisi kanan + 1
    return data[x+1][ki]+data[x+1][ka]+1;  // tabrakan sebelumnya + 1
}
int main(){
    scanf("%d%d%d", &bar, &kol, &nbatu);
    R(i,0,nbatu){
        scanf("%d%d%d%d", &a1,&b1,&a2,&b2);
        R(i,a1,a2+1) R(j,b1,b2+1)          //
            m[i][j]=1;                     // bikin grid
    }
    //R(i,1,bar+1) { R(j,1,kol+1) printf("%d ", m[i][j]); puts(""); }
    //puts("");
    RV(i,bar,0){
        R(j,1,kol+1){
            if(m[i][j]) data[i][j]=cari(i,j); // kalo 1 berarti batu, kalo batu berarti bisa ditabrak
            else data[i][j]=data[i+1][j];     // tabrakan sebelumnya || bisa nabrak bawahnya ga?
        }
    }
    //R(i,1,bar+1) { R(j,1,kol+1) printf("%d ", data[i][j]); puts(""); }
    maks=data[0][1];
    R(i,2,kol+1) maks=max(maks,data[0][i]);   // cari titik awal dengan tabrakan maksimal
    
    printf("%lld\n", maks);
    return 0;
}
