#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef pair<int,int> PII;
typedef pair<int,PII> PIE;

const int INF = 2000111222;

vector<PII> adj[3000];
int V, E, start, finish;

priority_queue<greater<PII>(),vector<PII> > q;



int main() {
    scanf("%d%d%d%d", &V, &E, &start, &finish);
    
    R(i,0,E) {
        int va,vi,w;
        scanf("%d%d%d", &va, &vi, &w);
        va--; vi--;
        adj[va].push_back(PII(vi,w));
        adj[vi].push_back(PII(va,w));
    }
    start--; finish--;
    vector<int> dist(V+2,INF);
    dist[start] = 0;
    q.push(PII(0,start));
    while(!q.empty()) {
        int di = q.top().first, u = q.top().second; q.pop();
        if(di == dist[u]) {
            int len = adj[u].size();
            R(i,0,len) {
                int vert = adj[u][i].first, w = adj[u][i].second;
                if(dist[vert] > dist[u] + w) {
                    dist[vert] = dist[u] + w;
                    q.push(PII(dist[vert],vert));
                }
            }
        }
    }
    printf("%d\n", dist[finish]);
    return 0;
}
