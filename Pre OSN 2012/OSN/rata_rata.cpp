#include <cstdio>
#include <algorithm>
using namespace std;

double a,mins,maks,rata,jumlah=0.00;
int n;
int main() {
    maks = -10e20;
    mins = 10e20;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%lf", &a);
        if( mins > a) mins = a;
        if( maks < a) maks = a;
        jumlah += a;
    }
    printf("%.2lf %.2lf %.2lf\n", mins, maks, jumlah);
    return 0;
}
