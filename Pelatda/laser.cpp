#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
typedef pair<int,int> PII;
typedef pair<PII,int> PIE;
typedef queue<PIE> Q_PIE;

Q_PIE q;

int bar, kol;
int dist[120][120];
int loka[2], loki[2];
char m[120][120];
bool vis[120][120];

void enqueue(int a, int b, int c) {
    if(!vis[a][b]) {
        q.push(PIE(PII(a,b),c));
        vis[a][b] = 1;
        dist[a][b]=c;
    }
}

void tw(int a, int b, int c, int d) {
    if(d==0 and a>0) {
        while(a>0 and m[a-1][b]!='*') {
            a--;
            enqueue(a,b,c);
        }
    } else
    if(d==1 and b<kol-1) {
        while(b<kol-1 and m[a][b+1]!='*') {
            b++;
            enqueue(a,b,c);
        }
    } else
    if(d==2 and a<bar-1) {
        while(a<bar-1 and m[a+1][b]!='*') {
            a++;
            enqueue(a,b,c);
        }
    } else
    if(d==3 and b>0) {
        while(b>0 and m[a][b-1]!='*') {
            b--;
            enqueue(a,b,c);
        }
    } else return ;
}

void bfs(int a, int b) {
    q.push(PIE(PII(a,b),0));
    dist[a][b]=0;
    while(!q.empty()) {
        PIE t = q.front(); q.pop();
        tw(t.first.first, t.first.second, t.second+1,0);
        tw(t.first.first, t.first.second, t.second+1,1);
        tw(t.first.first, t.first.second, t.second+1,2);
        tw(t.first.first, t.first.second, t.second+1,3);
    }
}

int main() {
    scanf("%d%d", &kol, &bar);
    R(i,0,bar) scanf("%s", &m[i]);
    int ctr = 0;
    R(i,0,bar) {
        R(j,0,kol) {
            if(m[i][j]=='C') {
                loka[ctr]=i;
                loki[ctr]=j;
                ctr++;
            }
        }
    }
    bfs(loka[0], loki[0]);
    //R(i,0,bar) R(j,0,kol) printf("%d%c", dist[i][j], j==kol-1?'\n':' ');
    printf("%d\n", dist[loka[1]][loki[1]]-1);
    return 0;
}
