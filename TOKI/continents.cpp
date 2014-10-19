#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef pair<int,int> PII;
char land;
int bar, kol, startx, starty, now = 0, ans = 0;
char m[30][30];

queue<PII> q;

void tw(int a, int b) {
    if(a>=0 and a<bar and b>=0 and b<kol and m[a][b] == land) {
        m[a][b] = land+1;
        q.push(PII(a,b));
    }
}

void bfs(int a, int b) {
    q.push(PII(a,b));
    m[a][b] = land+1;
    while(!q.empty()) {
        now++;
        PII t = q.front(); q.pop();
        tw(t.first-1,t.second);
        tw(t.first,(t.second+1)%kol);
        tw(t.first+1,t.second);
        tw(t.first,(t.second+kol-1)%kol);
    }
}

int main() {
  while(scanf("%d%d", &bar, &kol) > 0) {
    ans = 0;
    R(i,0,bar) scanf("%s", &m[i]);
    scanf("%d%d", &startx, &starty);
    land = m[startx][starty];
    q.push(PII(startx,starty));
    while(!q.empty()) {
        PII t = q.front(); q.pop();
        tw(t.first-1,t.second);
        tw(t.first,(t.second+1)%kol);
        tw(t.first+1,t.second);
        tw(t.first,(t.second+kol-1)%kol);
    }
    R(i,0,bar) {
        R(j,0,kol) {
            if(m[i][j] == land) {
                now = 0;
                bfs(i,j);
                ans = max(now, ans);
                //printf("%d %d %d\n", i, j, now);
            }
        }
    }
    printf("%d\n", ans);
  }
    return 0;
}
