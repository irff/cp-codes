#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, x[120], y[120], oddx=0,oddy=0,px,py;
int main() {
    while(scanf("%d", &n), n) {
        R(i,0,110) x[i]=0,y[i]=0;
        oddx = 0, oddy = 0;
        int a;
        R(i,0,n) R(j,0,n) scanf("%d", &a),(a)?x[i]++,y[j]++:0;
        R(i,0,n) {
            if(x[i]%2) oddx++,px = i;
            if(y[i]%2) oddy++,py = i;
        }
        if(oddx==0 and oddy==0) printf("OK\n");
        else if(oddx==1 and oddy==1) printf("Change bit (%d,%d)\n", px+1, py+1);
        else printf("Corrupt\n");
    }
    return 0;
}
