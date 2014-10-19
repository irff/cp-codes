#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef pair<int,int> PII;
typedef long long LLD;
typedef map<PII,LLD> MPB;

MPB m;

int bar, kol;
LLD jw=0;
LLD rek(int xa, int xb, int ya, int yb) {
    int selx = xb-xa;
    int sely = yb-ya;
    
    if(m[PII(selx,sely)]==0) {
      LLD ans = 0;
      if(selx%2==1 and selx>0 and sely%2==1 and sely>0) {
        int sela = selx, seli=sely;
        selx/=2; sely/=2;
        ans=1;
        ans+=rek(xa,xa+selx,ya,ya+sely);
        ans+=rek(xa,xa+selx,ya+sely+1,yb);
        ans+=rek(xa+selx+1,xb,ya,ya+sely);
        ans+=rek(xa+selx+1,xb,ya+sely+1,yb);
        return m[PII(sela,seli)]=ans;
      }
      return 0;
    }
    return m[PII(selx,sely)];
}

int main() {
    scanf("%d%d", &bar, &kol);
    jw=rek(0,bar,0,kol);
    printf("%lld\n", jw);
    return 0;
}
