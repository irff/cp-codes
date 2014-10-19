#include <cstdio>
#include <queue>
#include <stack>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define pb(x) push_back(x)

typedef pair<int,int> PII;
typedef vector<PII> VII;

int V, E;
bool vis[10111];
VII adj[10111];

int a = 0, b = 0 , w = 0;
int cost_kiri = 0, total = 0, cost_kanan = 0;

int main() {
    
    scanf("%d", &V);
    E = V;
    R(i,0,V) {
        scanf("%d%d%d", &a, &b, &w);
        total+=w;
        adj[a].pb(PII(b,0));
        adj[b].pb(PII(a,w));
    }
    
    stack<int> q;
    
    q.push(1);
    while(!q.empty()) {
        int u = q.top(); q.pop();
        vis[u] = 1;
        int len = adj[u].size();
        
        if(vis[ adj[u][0].first ] and vis[ adj[u][1].first ]) {
            if(adj[u][0].first==1) {
                cost_kanan += adj[u][0].second;
            } else {
                cost_kanan += adj[u][1].second;
            }
            break;
        }
        
        R(i,0,len) {
            int v = adj[u][i].first, w = adj[u][i].second;
            if(!vis[ v ]) {
                cost_kanan+=w;
                q.push(v);
            }
        }
    }
    
    //printf("\n");
    cost_kiri = total-cost_kanan;
    //printf("cost kanan = %d, ", cost_kanan);
    //printf("cost_kiri = %d\n", cost_kiri);
    printf("%d\n", min(cost_kiri,cost_kanan));
    return 0;
}
