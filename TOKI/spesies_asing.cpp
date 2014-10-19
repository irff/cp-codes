#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)


typedef struct {
    int a, b, c, d;
} spesies;

int na, nb, nc, mins_step = 2000111222, ctr = 0;
bool memo[260][260][260];
bool punah = 0;

queue<spesies> q;

void bfs() {
    q.push((spesies){na,nb,nc,0});
    while(!q.empty()) {
        spesies t = q.front(); q.pop();
        if(!memo[t.a][t.b][t.c]) {
            memo[t.a][t.b][t.c] = 1;
            ctr = 0; 
            if(!t.a) ctr++; if(!t.b) ctr++; if(!t.c) ctr++;
            if(ctr > 1) {
                mins_step = t.d;
                break;
            }
            if(t.a && t.b) q.push((spesies){t.a-1,t.b-1,t.c+2,t.d+1});
            if(t.a && t.c) q.push((spesies){t.a-1,t.b+2,t.c-1,t.d+1});
            if(t.b && t.c) q.push((spesies){t.a+2,t.b-1,t.c-1,t.d+1});
        }
    }
}

int main() {
    scanf("%d%d%d", &na, &nb, &nc);
    bfs();
    if(mins_step != 2000111222) printf("%d\n", mins_step);
    else printf("-1\n");
    return 0;
}
