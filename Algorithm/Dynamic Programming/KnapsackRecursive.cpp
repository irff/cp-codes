#include <cstdio>
#include <algorithm>
using namespace std;

int n,uang,hasil;
int w[1020],harga[1020];

int rek(int id, int sisa) {
    if(id>=n) return 0;
    if(harga[id]>sisa) return rek(id+1,sisa);
    return max(rek(id+1,sisa),rek(id+1,sisa-harga[id])+w[id]);
}

int main() {
    scanf("%d%d", &n,&uang);
    for(int i=0; i<n; i++) scanf("%d%d", &harga[i],&w[i]);
    hasil=rek(0,uang);
    printf("%d\n", hasil);
    return 0;
}
