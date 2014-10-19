#include <cstdio>
#include <algorithm>
using namespace std;


int n, nquery, num, cari=0, now=0;
int a[10200];
bool ketemu;
void bs(int awal, int akhir) {
    int mid = (awal+akhir)/2;
    if( awal > akhir) return ;
    if( a[mid] == cari and mid!=now) { ketemu=1; return; }
    if( a[mid] == cari and mid==now) {
        bs(mid+1, akhir);
        bs(awal, mid-1);
        return ;
    }
    if( a[mid] < cari) awal = mid+1;
    if( a[mid] > cari) akhir = mid-1;
    bs(awal, akhir);
}
int main() {
    scanf("%d%d", &n, &nquery);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    for(int i=0; i<nquery; i++) {
        scanf("%d", &num);
        ketemu=0; 
        for(int j=0; j<n and !ketemu; j++) {
            if(num > a[j]) {
                now = j;
                cari = num-a[j];
                bs(0,n);
            }
        }
        if(ketemu) printf("YA\n");
        else printf("TIDAK\n");
    }
  
    return 0;
}
