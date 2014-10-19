#include <cstdio>
#include <cmath>
using namespace std;

int awal,akhir;
int jumlah;
int komposit(int k){
    if(k==1) return 0;
    if(k==2) return 0;
    if(k%2==0) return 1;
    for(int j=3; j*j<=k; j++){
        if(k%j==0) return 1;
    }
    return 0;
}
int main(){
    scanf("%d%d", &awal, &akhir);
    jumlah=0;
    for(int i=awal; i<=akhir; i++){
        jumlah+=komposit(i);
    }
    printf("%d\n", jumlah);
    return 0;
}
