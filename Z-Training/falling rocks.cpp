#include <cstdio>
#include <cmath>
 
int teskes;
double vt,g;
int v0,h,i=0;
int main(){
    scanf("%d%lf", &teskes, &g);
    for(; i<teskes; i++){
        scanf("%d%d", &v0,&h);
        vt=v0*v0+g*h+g*h;
        vt=sqrt(vt);
        printf("%.4lf\n", vt);
    }
    return 0;
}
