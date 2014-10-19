#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef pair<int,int> PII;

int bar, kol, maks = 0, luas;
char m[600][600];
queue<PII> q;

void dfs(int a, int b) {
    if(a>=0 and a<bar and b>=0 and b<kol and m[a][b]=='x') {
        m[a][b]='.';
        luas++;
        q.push(PII(a,b));
    }
}

void bfs(int a, int b) {
    q.push(PII(a,b));
    m[a][b] = '.';
    luas++;
    while(!q.empty()) {
        PII t = q.front(); q.pop();
        a = t.first; b = t.second;
        dfs(a-1,b);
        dfs(a-1,b+1);
        dfs(a,b+1);
        dfs(a+1,b+1);
        dfs(a+1,b);
        dfs(a+1,b-1);
        dfs(a,b-1);
        dfs(a-1,b-1);
    }
}

int main() {
    scanf("%d%d", &bar, &kol);
    R(i,0,bar) scanf("%s", &m[i]);
    R(i,0,bar) {
        R(j,0,kol) {
            if(m[i][j]=='x') {
                luas = 0;
                bfs(i,j);
                maks=max(luas, maks);
            }
        }
    }
    printf("%d\n", maks);
    return 0;
}
