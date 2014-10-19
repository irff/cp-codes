#include <cstdio>

int bar, kol, vol;
int m[1020][1020];
int main() {
    scanf("%d%d%d", &bar, &kol, &vol);
    for(int i=0; i<bar; i++)
        for(int j=0; j<kol; j++) scanf("%d", &m[i][j]);
    double awal = 0.00;
    double akhir = 1000000.00;
    double mid = (double)(awal+akhir)/2;
    while( akhir-awal > 0.00001 ) {
        mid = (double)(awal+akhir)/2;
        double x = 0;
        for(int i=0; i<bar; i++) {
            for(int j=0; j<kol; j++) {
                if(mid - m[i][j] > 0.00001) {
                    x+=(mid-m[i][j]);
                }
            }
        }
        if(x > vol) akhir = mid;
        else {
            awal = mid;
        }
    }
    printf("%.3f\n", mid);
    return 0;
}
