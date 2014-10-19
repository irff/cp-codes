#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int m[200][200], v[200][200];
int bar, kol, now = 0, ans = 0;
bool vis[200][200], bukit = 0;

void dfs(int a, int b) {
    if(a>=0 and a<bar and b>=0 and b<kol) {
        if(m[a][b]==now and !vis[a][b]) {
            vis[a][b] = 1;
            dfs(a-1,b);
            dfs(a-1,b+1);
            dfs(a,b+1);
            dfs(a+1,b+1);
            
            dfs(a+1,b);
            dfs(a+1,b-1);
            dfs(a,b-1);
            dfs(a-1,b-1);
        } else if(m[a][b] > now) {
            bukit = 0;
        }
    }
}

int main() {
    scanf("%d%d", &bar, &kol);
    R(i,0,bar) R(j,0,kol) scanf("%d", &m[i][j]);
    R(i,0,bar) {
        R(j,0,kol) {
            if(!vis[i][j]) {
                now = m[i][j];
                bukit = 1;
                dfs(i,j);
                if(bukit) ans++;
            }
        }
    }
    printf("%d\n", ans);
}
