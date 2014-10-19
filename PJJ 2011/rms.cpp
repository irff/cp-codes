#include <cstdio>
#include <cmath>
#include <cstdlib>
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n;
double x[10200];
double hasil;

double rek(double a, double b) {
    double ha=0.00,hb=0.00, mid = (double) (a+b)/2;
    R(i,0,n) {
        double t=(double) fabs(x[i]-a),u=(double) fabs(x[i]-b);
        ha += (double) sqrt( t*t*t );
        hb += (double) sqrt( u*u*u );
    }
    if( a==b) return a;
    if( hb > ha) return rek(a,mid);
    return rek(mid,b);
}

int main() {
    scanf("%d", &n);
    R(i,0,n) {
        scanf("%lf", &x[i]);
    }
    hasil=rek(0,1000);
    printf("%.2lf\n", hasil);
}
