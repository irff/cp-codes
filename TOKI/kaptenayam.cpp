#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define MAKS 10000

int teskes,n;
int ayam[MAKS], lisa[MAKS],lisi[MAKS];
int kapten,anggota;

int main(){
        scanf("%d", &n);
        R(i,0,n) { lisa[i]=1; lisi[i]=1; }
        R(i,0,n) scanf("%d", &ayam[i]);
        R(i,1,n){
            R(j,0,i){
                if(ayam[i]>ayam[j] and lisa[i]<=lisa[j])
                    lisa[i]=lisa[j]+1;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=n-1; j>i; j--){
                if(ayam[i]>ayam[j] and lisi[i]<=lisi[j])
                    lisi[i]=lisi[j]+1;
            }
        }
        R(i,1,n)
           if(lisa[kapten]+lisi[kapten]<lisa[i]+lisi[i]) kapten=i;
        anggota=lisa[kapten]+lisi[kapten]-1;
        kapten++;
        printf("%d %d\n", kapten, anggota);
    return 0;
}
