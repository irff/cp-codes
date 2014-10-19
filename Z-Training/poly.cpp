#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define pi acos(-1)

int n;
double r,peri,area;
int main(){
    scanf("%d%lf", &n,&r);
    area=(r*r)*n*sin(2*(double)pi/n)/2;
    peri=r*2*sin((double)pi/n)*n;
    printf("%.5lf\n%.5lf\n", peri,area);
    scanf("\n");
    return 0;
}
