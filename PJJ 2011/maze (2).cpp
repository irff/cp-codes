#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int bar, kol, m[120][120], dist[120][120], px,py;

typedef pair<int,int> PII;
typedef pair<PII,int> PIII;

queue<PIII> q;

void tw(int a, int b, int c) {
    if( a>=0 and a<bar and b>=0 and b<kol and m[a][b]!=-1) {
        m[a][b]=-1;
        dist[a][b] = c;
        q.push(PIII(PII(a,b),c));
    }
}

void bfs(int a, int b) {
    dist[a][b]=0;
    q.push(PIII(PII(a,b),0));
    m[a][b]=-1;
    while(!q.empty()) {
        PIII t = q.front();
        q.pop();
        tw(t.first.first-1, t.first.second, t.second+1);
        tw(t.first.first, t.first.second+1, t.second+1);
        tw(t.first.first+1, t.first.second, t.second+1);
        tw(t.first.first, t.first.second-1, t.second+1);
    }
}

int main() {
    memset(dist, -1, sizeof dist);
    scanf("%d%d", &bar, &kol);
    R(i,0,bar) R(j,0,kol) scanf("%d", &m[i][j]);
    scanf("%d%d", &px, &py);
    bfs(px-1,py-1);
    int mins = 2000111222;
    R(i,0,bar) {
        if(dist[i][0]!=-1) mins=min(dist[i][0],mins);
        if(dist[i][kol-1]!=-1) mins=min(dist[i][kol-1],mins);
    }
    R(j,0,kol) {
        if(dist[0][j]!=-1) mins=min(dist[0][j],mins);
        if(dist[bar-1][j]!=-1) mins=min(dist[bar-1][j],mins);
    }
    printf("%d\n", mins+1);
    return 0;
}
