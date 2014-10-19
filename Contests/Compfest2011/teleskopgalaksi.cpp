#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes,n;
struct galaksi {
       int x,y,r;
       } ;
double maks;
galaksi g[200];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        maks=-1;
        scanf("%d", &n);
        R(i,0,n) scanf("%d%d%d", &g[i].x,&g[i].y,&g[i].r);
        R(i,0,n) R(j,i,n) {
            double jarak=g[i].r+g[j].r+abs(sqrt((g[i].y-g[j].y) * (g[i].y-g[j].y) + (g[i].x-g[j].x) * (g[i].x-g[j].x)));
            if(jarak>maks) maks=jarak;
        }
        printf("%.2lf\n", (double)maks/2);
        
    }
    return 0;
}
