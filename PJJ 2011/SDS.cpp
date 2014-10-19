#include <cstdio>
#include <cmath>

double x,maks=-1000123.00,mins=1000123.00,sum,rata,quadsum,sds;
int n;
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%lf", &x);
        sum+=x;
        quadsum+=(x*x);
        if(x>=maks) maks=x;
        if(x<=mins) mins=x;
    }
    rata=(double)sum/n;
    sds=sqrt( (double)(quadsum - rata*rata*n)/(n-1));
    printf("%.2lf %.2lf %.2lf %.2lf\n", mins,maks,rata,sds);
    return 0;
}
