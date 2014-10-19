#include <cstdio>
#include <cmath>

int a[52000], n, lubang;
int main() {
    scanf("%d%d", &n, &lubang);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    double awal = 0.00;
    double akhir = 2000000000.00;
    double mid = 1000000000.00;
    while( akhir-awal > 0.0001 ) {
        //printf("%.2f %.2f\n", awal, akhir);
        int x_lubang = 0;
        mid = (double)(awal+akhir)/2;
        for(int i=0; i<n; i++) x_lubang += (int)ceil(a[i]/mid);
        if( x_lubang > lubang) {
            awal = mid;
        } else {
            akhir = mid;
        }
    }
    printf("%.2f\n", mid);
}
