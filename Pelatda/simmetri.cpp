#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef pair<int,int> PII;
typedef map<PII,bool> MPB;
typedef long long LLD;
MPB m;

int bar, kol, ans = 0;

LLD rek(int xa, int xb, int ya, int yb) {
    int selx = xb-xa;
    int sely = yb-ya;
    //printf("xa: %d, xb: %d, ya: %d, yb: %d\n", xa, xb, ya, yb); 
    //printf("%d %d\n", selx, sely);
    if(m[PII(selx,sely)]!=0) return m[PII(selx,sely)];
    if(selx%2==1 and selx>0 and sely%2==1 and sely>0) {
        LLD ans=0;
        ans++;
        selx/=2; sely/=2;
        ans+=rek(xa,xa+selx,ya,ya+sely);
        ans+=rek(xa,xa+selx,ya+sely+1,yb);
        ans+=rek(xa+selx+1,xb,ya,ya+sely);
        ans+=rek(xa+selx+1,xb,ya+sely+1,yb);
        return m[PII(selx,sely)]=ans;
    }
    return 0;
}

int main() {
    scanf("%d%d", &bar, &kol);
    LLD jawab = rek(0,bar,0,kol);
    printf("%lld\n", jawab);
    return 0;
}
