#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int v1,v2,dist[1200],n=0;
vector<int> adj[1200];

void bfs(int s) {
    dist[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int u=q.front(); q.pop();
        int ukuran=adj[u].size();
        for(int i=0; i<ukuran; i++) {
            int v=adj[u][i];
            if(dist[v]==-1) {
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
}

int main() {
    memset(dist, -1, sizeof dist);
    while(scanf("%d", &v1) >0 and v1!=-1) {
        scanf("%d", &v2);
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
        n=max(n,max(v1,v2));
    }
    bfs(0);
    int maks=-1;
    for(int i=0; i<n+1; i++) if(dist[i] > maks) maks=dist[i];
    printf("%d\n", maks);
    return 0;
}
