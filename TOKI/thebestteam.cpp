#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,a,b) for(int i=int(a);i<int(b);i++)

int teskes,n,s[200][200];
long jumlah;
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        scanf("%d", &n);
        jumlah=0;
        R(i,0,n) R(j,0,n) scanf("%d", &s[i][j]);
        R(i,0,n) R(j,i+1,n) R(k,j+1,n) jumlah=max(jumlah,(long)s[i][j]*s[i][k]*s[j][k]);
        printf("%ld\n", jumlah);
    }
    return 0;
}
