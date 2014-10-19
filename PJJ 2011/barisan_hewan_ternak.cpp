#include <cstdio>
#include <algorithm>
using namespace std;

int n, nquery, cari=0;
int a[120000];

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int num;
        scanf("%d", &num);
        if(i==0) a[i]=num;
        else a[i]=a[i-1]+num;
    }
    scanf("%d", &nquery);
    for(int i=0; i<nquery; i++) {
        scanf("%d", &cari);
        int awal =0, akhir = n;
        int mid = (awal+akhir)/2;
        while(awal <= akhir) {
            mid = (awal+akhir)/2;
            //printf("%d %d %d\n", awal, akhir, mid);
            if(cari <= a[mid] and cari > a[mid-1]) break;
            if(cari < a[mid]) akhir = mid;
            if(cari > a[mid]) awal = mid;
        }
        printf("%d\n", mid+1);
    }

    return 0;
}
