#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define x first
#define y second

typedef pair<int,int> PII;
typedef long long LLD;

LLD mins,hasil;
vector<PII> vx,vy;
int teskes,n,numx,numy;
int minx,miny,maxx,maxy;
bool same(PII a, PII b) {
    if(a.x==b.y and a.y==b.x) return 1;
    return 0;
}
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        vx.clear();
        vy.clear();
        mins=2000111222333444;
        scanf("%d", &n);
        R(i,0,n) {
            scanf("%d%d", &numx,&numy);
            vx.push_back(PII(numx,numy));
            vy.push_back(PII(numy,numx));
        }
        sort(vx.begin(),vx.end());
        sort(vy.begin(),vy.end());
        
        //-------CUTTING A TREE
        // Min X
        minx=vx[1].x;
        maxx=vx[n-1].x;
        if(same(vx[0],vy[0])) miny=vy[1].x;
        else miny=vy[0].x;
        if(same(vx[0],vy[n-1])) maxy=vy[n-2].x;
        else maxy=vy[n-1].x;
        mins=min(mins, (LLD)abs( (maxx-minx)*(maxy-miny) ) );
        // Max X;
        minx=vx[0].x;
        maxx=vx [n-2].x;
        if(same(vx[n-1],vy[0])) miny=vy[1].x;
        else miny=vy[0].x;
        if(same(vx[n-1],vy[n-1])) maxy=vy[n-2].x;
        else maxy=vy[n-1].x;
        mins=min(mins, (LLD)abs( (maxx-minx)*(maxy-miny) ) );
        // Min Y
        miny=vy[1].x;
        maxy=vy[n-1].x;
        if(same(vy[0],vx[0])) minx=vx[1].x;
        else minx=vx[0].x;
        if(same(vy[0],vx[n-1])) maxx=vx[n-2].x;
        else maxx=vx[n-1].x;
        mins=min(mins, (LLD)abs( (maxx-minx)*(maxy-miny) ) );
        // Max Y
        miny=vy[0].x;
        maxy=vy[n-2].x;
        if(same(vy[n-1],vx[0])) minx=vx[1].x;
        else minx=vx[0].x;
        if(same(vy[n-1],vx[n-1])) maxx=vx[n-2].x;
        else maxx=vx[n-1].x;
        mins=min(mins, (LLD)abs( (maxx-minx)*(maxy-miny) ) );
        printf("%lld\n", mins);
    }
    return 0;
}
