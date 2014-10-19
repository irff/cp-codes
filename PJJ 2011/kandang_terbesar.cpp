#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_a);i--)

typedef pair<int,int> PII;

queue<PII> q;
int bar, kol;
char m[1000][1000], ori[1000][1000];

int bx, by, kx, ky, ctr = 0;

void dfs(int a, int b) {
    if(a >= 0 and a < bar and b >= 0 and b < kol and m[a][b] == '.') {
        ctr++;
        m[a][b] = '#';
        dfs(a-1, b);
        dfs(a, b+1);
        dfs(a+1, b);
        dfs(a, b-1);
    }
}

void tw(int a, int b) {
    if(a >= 0 and a < bar and b >= 0 and b < kol and m[a][b] == '.') {
        q.push(PII(a,b));
        m[a][b] = '#';
    }
}

void bfs(int a, int b) {
    q.push(PII(a,b));
    m[a][b] = '#';
    while(!q.empty()) {
        ctr++;
        a = q.front().first, b = q.front().second;
        q.pop();
        tw(a-1, b);
        tw(a, b+1);
        tw(a+1, b);
        tw(a, b-1);
    }
}

int main() {
    scanf("%d%d", &kol, &bar);
    R(i,0,bar) scanf("%s", &m[i]);
    R(i,0,bar) {
        R(j,0,kol) {
            if(m[i][j] == 'B') {
                bx = i, by = j;
            } else
            if(m[i][j] == 'K') {
                kx = i, ky = j;
            }
        }
    }
    R(i,0,bar) strcpy(ori[i], m[i]);
    int bebek = 0, kucing = 0;
    m[bx][by] = '.';
    bfs(bx, by);
    bebek = ctr;
    ctr = 0;
    R(i,0,bar) strcpy(m[i], ori[i]);
    m[kx][ky] = '.';
    bfs(kx, ky);
    kucing = ctr;
    if(bebek > kucing) printf("B %d\n", bebek-kucing);
    else if(bebek < kucing) printf("K %d\n", kucing-bebek);
    else printf("SERI\n");
    return 0;
}
