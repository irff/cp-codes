#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n;
double num[52000];
const double eps = 10e-5;
void binary(double awal, double akhir) {
     double mid = (double)(awal+akhir)/2;
     double suma = 0.00, sumb = 0.00;
     for(int i=0; i<n; i++) {
         double p = fabs(num[i]-awal)*fabs(num[i]-awal)*fabs(num[i]-awal);
         suma+=sqrt(p);
     }
     for(int i=0; i<n; i++) {
         double p = fabs(num[i]-akhir)*fabs(num[i]-akhir)*fabs(num[i]-akhir);
         sumb+=sqrt(p);
     }
     if(fabs(suma-sumb) < eps) {
         printf("%.2lf\n", mid);
         return ;
     } else if( suma > sumb) { binary(mid, akhir); }
     else if( suma < sumb) { binary(awal, mid); }
     
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%lf", &num[i]);
    }
    binary(-1000.00, 1000.00);
    return 0;
}
