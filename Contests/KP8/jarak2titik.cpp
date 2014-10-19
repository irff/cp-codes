#include <cstdio>
#include <cstdlib>
#include <cmath>

int teskes,xa,xb,ya,yb;
double jarak;

int main () {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
        jarak=sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
        printf("%.3lf\n", jarak);
    }
    
}
