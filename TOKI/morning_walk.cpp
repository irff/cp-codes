#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

bool degree[300];
int V, E, x, y;
vector<int> adj[300];
bool vis[300];
void dfs(int u) {
    if(!vis[u]) {
        vis[u] = 1;
        int len = adj[u].size();
        R(i,0,len) {
            if(!vis[ adj[u][i] ]) {
                dfs(adj[u][i]);
            }
        }
    }
}

int main() {
    while( scanf("%d%d", &V, &E) > 0) {
        memset(adj, 0, sizeof adj);
        memset(vis, 0, sizeof vis);
        R(i,0,V+1) degree[i] = 0;
        R(i,0,E) {
            scanf("%d%d", &x, &y);
            adj[x].push_back(y);
            adj[y].push_back(x);
            degree[x]=1-degree[x];
            degree[y]=1-degree[y];
        }
        int com = 0;
        R(i,0,V) {
            if(!vis[i]) {
                com++;
                dfs(i);
            }
        }
        //printf("com = %d\n", com);
        bool odd = 0;
        R(i,0,V) {
            if(degree[i]) odd = 1;
        }
        if(!odd and com==1) printf("Possible\n");
        else printf("Not Possible\n");
    }
    return 0;
}
