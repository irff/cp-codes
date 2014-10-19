#include <cstdio>
#include <algorithm>
using namespace std;

int ntoko,maks,coba=0,nitem[30],makstoko[30];
int v[30][30], w[30][30];
int hasil=0;
int ambil[100];
int rek(int idi, int idj, int ke, int sisa) {
    if(idi >= ntoko) return 0;
    if( idj >= nitem[idi]) return rek(idi+1,0,0,sisa);
    if(sisa==0) return 0;
    coba=0;
    for(int i=0; i<=sisa; i++) {
        if( sisa >= i*w[idi][idj]) {
            ambil[i]=rek(idi,idj+1,1,sisa-i*w[idi][idj])+i*v[idi][idj]+(i/3)*makstoko[i];
            coba=max(maks,ambil[i]);
        }
    }
    return max( coba, rek(idi+1,0,0,sisa));
}

int main() {
    scanf("%d %d", &ntoko, &maks);
    for(int i=0; i<ntoko; i++) {
        scanf("%d", &nitem[i]);
        for(int j=0; j<nitem[i]; j++) {
            scanf("%d%d", &w[i][j], &v[i][j]);
            makstoko[i]=max(makstoko[i],v[i][j]);
        }
    }
    hasil=rek(0,0,0,maks);
    printf("%d\n", hasil);
    return 0;
}
