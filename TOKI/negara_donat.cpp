#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define pb(x) push_back(x)

typedef pair<int,int> PII;
typedef vector<int> VI;
int V, E;
bool vis[10111];
VI adj[10111];
VI kiri[10111], kanan[10111];

int cost_kiri = 0, cost_kanan = 0;

void dfs(int u) {
    printf("%d ", u+1);
    int len = adj[u].size();
    vis[u] = 1;
    R(i,0,len) {
        if(!vis[ adj[u][i] ]) {
            cost_kiri+=kiri[u][i];
            cost_kanan+=kanan[u][i];
            dfs(adj[u][i]);
        }
    }
}

int main() {
    scanf("%d", &V);
    E = V;
    R(i,0,E) {
        int a,b,w;
        scanf("%d%d%d", &a, &b, &w);
        a--, b--;
        
        adj[a].pb(b);
        kiri[a].pb(0);
        kiri[b].pb(w);
        
        adj[b].pb(a);
        kanan[a].pb(w);
        kanan[b].pb(0);
    }
    dfs(0);
    printf("\n");
    cost_kiri+=kiri[0][1];
    cost_kanan+=kanan[0][1];
    printf("%d\n", min(cost_kiri,cost_kanan));
    return 0;
}
