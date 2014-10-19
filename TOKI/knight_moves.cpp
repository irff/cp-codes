#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef struct {
    int a, b, w;
} qyu;

char sa[5], si[5], sx,sy,fx,fy;

int dist[9][9][9][9], aa = 0, bb = 0;
bool m[9][9];

queue<qyu> q;

void tw(int a, int b, int w) {
    if(a>=0 and a<8 and b>=0 and b<8 and !m[a][b]) {
        m[a][b] = 1;
        dist[aa][bb][a][b] = w;
        q.push((qyu){a,b,w});
    }
}

void bfs() {
    m[aa][bb] = 1;
    q.push((qyu){aa,bb,0});
    dist[aa][bb][aa][bb] = 0;
    while(!q.empty()) {
        qyu t = q.front(); q.pop();
        tw(t.a-1, t.b-2, t.w+1);
        tw(t.a-1, t.b+2, t.w+1);
        tw(t.a+1, t.b-2, t.w+1);
        tw(t.a+1, t.b+2, t.w+1);
        
        tw(t.a-2, t.b+1, t.w+1);
        tw(t.a-2, t.b-1, t.w+1);
        tw(t.a+2, t.b+1, t.w+1);
        tw(t.a+2, t.b-1, t.w+1);
    }
}

int main() {
    memset(dist, 0, sizeof dist);
    R(i,0,8) {
        R(j,0,8) {
            memset(m, 0, sizeof m);
            aa = i, bb = j;
            bfs();
        }
    }
    while(scanf("%s%s", &sa, &si) > 0) {
        sx = sa[0]-'a', sy = sa[1]-'0'-1;
        fx = si[0]-'a', fy = si[1]-'0'-1;
        printf("To get from %s to %s takes %d knight moves.\n", sa, si, dist[sx][sy][fx][fy]);
    }
    return 0;
}
