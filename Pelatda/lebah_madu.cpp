#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

//typedef pair<char,char> PII;
const int INF = 2000111222;
typedef pair<short,short> PSS;
typedef pair<PSS,int> PSSI;

int bar, kol;
short pa[251000], pi[251000];
int npohon=0,now = 0;
short startx,starty,finishx,finishy;
char m[600][600];
int d[600][600];
bool vis[502][502], bisa = 0;
queue<PSSI> q;
queue<PSS> v;
/*
void fills(short a, short b, int c) {
    if(a>=0 and a<bar and b>=0 and b<kol and d[a][b]>c) {
        d[a][b]=c;
        fills(a-1,b,c+1);
        fills(a,b+1,c+1);
        fills(a+1,b,c+1);
        fills(a,b-1,c+1);
    }
}
*/
void tw(int a, int b, int c) {
    if(a>=0 and a<bar and b>=0 and b<kol)
        if(d[a][b]>c) {
            d[a][b]=c;
            q.push(PSSI(PSS(a,b),c));
        }
}
void bfills() {
    short a, b; int c;
    while(!q.empty()) {
        PSSI x = q.front(); q.pop();
        a = x.first.first, b = x.first.second;
        c = x.second;
        tw(a-1,b,c+1);
        tw(a,b+1,c+1);
        tw(a+1,b,c+1);
        tw(a,b-1,c+1);
    }
}
/*
void bfs(short i, short j) {
  if(d[i][j]>=now) {
    v.push(PSS(i,j));
    while(!v.empty() and !bisa) {
        short a = v.front().first, b = v.front().second; v.pop();

        if(a==finishx and b==finishy) { bisa = 1; break; }

        vis[a][b] = 1;
        a--;
        if(a>=0 and a<bar and b>=0 and b<kol and !bisa and !vis[a][b] and d[a][b]>=now) v.push(PSS(a,b));
        a++; b++;
        if(a>=0 and a<bar and b>=0 and b<kol and !bisa and !vis[a][b] and d[a][b]>=now) v.push(PSS(a,b));
        a++; b--;
        if(a>=0 and a<bar and b>=0 and b<kol and !bisa and !vis[a][b] and d[a][b]>=now) v.push(PSS(a,b));
        a--; b--;
        if(a>=0 and a<bar and b>=0 and b<kol and !bisa and !vis[a][b] and d[a][b]>=now) v.push(PSS(a,b));
    }
    while(!v.empty()) v.pop();
  }
}
*/
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
            d[i][j]=0;
            npohon++;
        }
        if(m[i][j]=='D') startx = i, starty = j;
        if(m[i][j]=='G') finishx = i, finishy = j;
    }
    //printf("s %d %d\n", startx, starty);
    //printf("f %d %d\n", finishx, finishy);
    R(i,0,npohon) {
        q.push(PSSI(PSS(pa[i],pi[i]),0));
    }
    
    bfills();
    
    int ki = 0, ka = bar*kol;
    
    while(ki<ka) {
        //printf("%d %d %d\n", ki, ka, now);
        bisa = 0;
        now = (ki+ka)/2+1;
        memset(vis, 0, sizeof vis);
        dfs(startx,starty);
        //printf("%d %d\n", i, bisa);
        
        if(bisa) ki = now;
        else {
            ka = now-1;
        }
        
    }
    
    //printf("%d %d %d\n", ki, ka, now);
    printf("%d\n", ki);
    //R(i,0,bar) R(j,0,kol) printf("%d%c", d[i][j],(j==kol-1)?'\n':' ');
    //R(i,0,bar) R(j,0,kol) printf("%d%c", d[i][j],(j==kol-1)?'\n':' ');
    
    //printf("0\n");
    return 0;
}
