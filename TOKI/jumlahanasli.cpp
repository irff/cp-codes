#include <cstdio>
using namespace std;

long long teskes, angka, jumlah;
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        jumlah=0;
        angka=0;
        scanf("%d", &angka);
        jumlah=(angka*(angka+1))/2;
        printf("%lld\n", jumlah);
    }
    return 0;
}
