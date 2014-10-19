#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double E = 2.7182818284;

double p,q,r,s,t,u;

double f(double x) {
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main() {

    while(scanf("%lf%lf%lf%lf%lf%lf", &p, &q, &r, &s, &t, &u) >0 ){
        double awal = 0.0000, akhir = 1.0000;
        double x = 0.0000;
        
        if(f(0)*f(1) > 0) printf("No solution\n");
        else {
            while( fabs(akhir-awal) > 1e-7) {
                x = (double)(awal+akhir)/2;
                if( f(x) > 0 ) awal = x;
                else akhir = x;
            }
            printf("%.4lf\n", x);
        }
        
    }
    return 0;
}
