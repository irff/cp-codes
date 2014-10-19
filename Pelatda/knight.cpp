#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef pair<int,int> PII;
typedef pair<PII,int> PIE;
queue<PIE> q;
int startx,starty,finishx,finishy;
int bar, kol, dist[200][200];

char m[200][200], sampah[100];

void tw(int a, int b, int c) {
    if(a>=0 and a<bar and b>=0 and b<kol and m[a][b]!='*') {
        m[a][b] = '*';
        dist[a][b] = c;
        q.push(PIE(PII(a,b),c));
    }
}

int main() {
    gets(sampah);
    scanf("%d%d", &kol, &bar);
    R(i,0,bar) scanf("%s", &m[i]);
    R(i,0,bar) R(j,0,kol) {
        if(m[i][j]=='K') startx = i, starty = j;
        if(m[i][j]=='H') finishx = i, finishy = j;
    }
    q.push(PIE(PII(startx, starty),0));
    dist[startx][starty]=0;
    m[startx][starty]='*';
    while(!q.empty()) {
        PIE t = q.front(); q.pop();
        tw(t.first.first-1, t.first.second-2, t.second+1);
        tw(t.first.first-2, t.first.second-1, t.second+1);
        
        tw(t.first.first+1, t.first.second-2, t.second+1);
        tw(t.first.first+2, t.first.second-1, t.second+1);
        
        tw(t.first.first+1, t.first.second+2, t.second+1);
        tw(t.first.first+2, t.first.second+1, t.second+1);
        
        tw(t.first.first-1, t.first.second+2, t.second+1);
        tw(t.first.first-2, t.first.second+1, t.second+1);
    }
    /*
    R(i,0,bar) {
        R(j,0,kol) printf("%d ", dist[i][j]);
    }*/
    printf("%d\n", dist[finishx][finishy]);
    return 0;
}
