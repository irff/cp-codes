#include <cstdio>

double x,maks=-1000123.00,mins=1000123.00,sum;
int n;
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%lf", &x);
        sum+=x;
        if(x>=maks) maks=x;
        if(x<=mins) mins=x;
    }
    printf("%.2lf %.2lf %.2lf\n", mins,maks,(double)sum/n);
    return 0;
}
