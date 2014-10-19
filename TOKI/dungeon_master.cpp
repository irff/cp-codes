#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef struct {
    int a, b, c, w;
} qyu;
queue<qyu> q;
int dal, bar, kol;
char m[31][31][31];
int dist[31][31][31];

void tw(int a, int b, int c, int w) {
    if(a>=0 and a<dal and b>=0 and b<bar and c>=0 and c<kol and m[a][b][c]!='#') {
        m[a][b][c] = '#';
        dist[a][b][c] = w;
        q.push((qyu){a,b,c,w});
    }
}

int main() {
    while( scanf("%d%d%d", &dal, &bar, &kol), dal) {
      memset(dist, -1, sizeof dist);
      R(i,0,dal) {
        R(j,0,bar) {
            scanf("%s", &m[i][j]);
        }
      }
      int sx = 0, sy = 0, sz = 0, fx = 0, fy = 0, fz = 0;
      R(i,0,dal) {
        R(j,0,bar) {
          R(k,0,kol) {
            if(m[i][j][k] == 'S') {
              sx = i, sy = j, sz = k;
            }
            if(m[i][j][k] == 'E') {
              fx = i, fy = j, fz = k;
            }
          }
        }
      }
      dist[sx][sy][sz] = 0;
      q.push((qyu){sx,sy,sz,0});
      while(!q.empty()) {
          qyu t = q.front(); q.pop();
          tw(t.a-1, t.b, t.c, t.w+1);
          tw(t.a, t.b-1, t.c, t.w+1);
          tw(t.a, t.b, t.c+1, t.w+1);
          tw(t.a, t.b+1, t.c, t.w+1);
          tw(t.a, t.b, t.c-1, t.w+1);
          tw(t.a+1, t.b, t.c, t.w+1);
      }
      if(dist[fx][fy][fz]==-1) {
          printf("Trapped!\n");
      } else {
          printf("Escaped in %d minute(s).\n", dist[fx][fy][fz]);
      }
    }
    
    return 0;
}
