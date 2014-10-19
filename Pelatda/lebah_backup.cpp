#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef pair<short,short> PII;
const int INF = 2000111222;

int bar, kol;
short pa[251000], pi[251000];
int npohon=0,now = 0;
short startx,starty,finishx,finishy;
char m[600][600];
int d[600][600];
bool vis[503][503], bisa = 0;

queue<PII> q;

void fills(short a, short b, int c) {
    if(a>=0 and a<bar and b>=0 and b<kol and d[a][b]>c) {
        d[a][b]=c;
        fills(a-1,b,c+1);
        fills(a,b+1,c+1);
        fills(a+1,b,c+1);
        fills(a,b-1,c+1);
    }
}

void bfs(short i, short j) {
  if(d[i][j]>=now) {
    q.push(PII(i,j));
    while(!q.empty() and !bisa) {
        short a = q.front().first, b = q.front().second; q.pop();

        if(a==finishx and b==finishy) { bisa = 1; break; }

        vis[a][b] = 1;
        a--;
        if(a>=0 and a<bar and b>=0 and b<kol and !bisa and !vis[a][b] and d[a][b]>=now) q.push(PII(a,b));
        a++; b++;
        if(a>=0 and a<bar and b>=0 and b<kol and !bisa and !vis[a][b] and d[a][b]>=now) q.push(PII(a,b));
        a++; b--;
        if(a>=0 and a<bar and b>=0 and b<kol and !bisa and !vis[a][b] and d[a][b]>=now) q.push(PII(a,b));
        a--; b--;
        if(a>=0 and a<bar and b>=0 and b<kol and !bisa and !vis[a][b] and d[a][b]>=now) q.push(PII(a,b));
    }
    while(!q.empty()) q.pop();
  }
}
void dfs(short a, short b) {
    //printf("%d %d %d-%d\n", a, b, vis[a][b], now);
    if(a>=0 and a<bar and b>=0 and b<kol and !bisa and !vis[a][b] and d[a][b]>=now) {
        //printf("%d %d %d\n", now, a, b);
        if(a==finishx and b==finishy) { bisa = 1; return ; }
        vis[a][b] = 1;
        dfs(a-1,b);
        dfs(a,b+1);
        dfs(a+1,b);
        dfs(a,b-1);
    }
}

int main() {
    scanf("%d%d", &bar, &kol);
    R(i,0,bar) scanf("%s", &m[i]);
    R(i,0,bar) R(j,0,kol) d[i][j] = INF;
    R(i,0,bar) R(j,0,kol) {
        if(m[i][j]=='#') {
            pa[npohon]=i;
            pi[npohon]=j;
            npohon++;
        }
        if(m[i][j]=='D') startx = i, starty = j;
        if(m[i][j]=='G') finishx = i, finishy = j;
    }
    
    R(i,0,npohon) {
        fills(pa[i],pi[i],0);
    }
    
    int ki = 0, ka = bar*kol;
    
    while(ki<ka) {
        bisa = 0;
        now = (ki+ka+1)/2;
        memset(vis, 0, sizeof vis);
        dfs(startx,starty);
        
        if(bisa) ki = now;
        else {
            ka = now-1;
        }
        
    }
    printf("%d\n", ki);
    return 0;
}
