#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define pb(x) push_back(x)

typedef pair<int,int> PII;

int teskes, V, E, ans = 0;
vector<int> adj[300];
bool vis[300], dist[300], impos;

int bfs(int a) {
    int all = 0, black = 0;
    queue<int> q;
    q.push(a);
    dist[a] = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = 1;
        all++;
        if(dist[u]==1) black++;
        
        int len = adj[u].size();
        R(i,0,len) {
            int v = adj[u][i];
            if(!vis[ v ]) {
                q.push( v );
                dist[v] = 1 - dist[u];
            } else {
                if(dist[u] == dist[v]) return -1;
            }
        }
    }
    if(all==1) return 1;
    return min(black, all-black);
}

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        impos = 0, ans = 0;
        
        memset(vis, 0, sizeof vis);
        memset(dist, 0, sizeof dist);
        
        scanf("%d%d", &V, &E);
        R(i,0,V+1) adj[i].clear();
        R(i,0,E) {
            int a, b; scanf("%d%d", &a, &b);
            adj[a].pb(b);
            adj[b].pb(a);
        }
        for(int i=0; i<V and !impos; i++) {
            if(!vis[i]) {
                int x = bfs(i);
                if(x == -1) impos = 1;
                else ans += x;
            }
        }
        if(impos) printf("-1\n");
        else printf("%d\n", ans);
    }
    return 0;
}
