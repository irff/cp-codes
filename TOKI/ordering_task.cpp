#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

int V, E;
vector<int> ans, adj[200];
bool vis[200];

void dfs(int u) {
    vis[u] = 1;
    int len = adj[u].size();
    R(i,0,len) {
        if(!vis[ adj[u][i] ]) {
            dfs(adj[u][i]);
        }
    }
    ans.push_back(u);
    
}

int main() {
    while(scanf("%d%d", &V, &E) and !(V==0 and E==0)) {
        ans.clear(); memset(vis, 0, sizeof vis);
        R(i,0,E) {
            int a, b;
            scanf("%d%d", &a, &b);
            adj[a-1].push_back(b-1);
        }
        R(i,0,V) {
            if(!vis[i]) {
                dfs(i);
            }
        }
        int len = ans.size();
        RV(i,len-1,0) printf("%d%c", ans[i]+1, i==0?'\n':' ');
    }

    return 0;
}
