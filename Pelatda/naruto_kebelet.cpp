#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

const int INF = 2000111222;
typedef pair<int,int> PII;
typedef vector<PII> VII;

VII adj[1100];
priority_queue< greater<PII>(), vector<PII> > q;

int V, E, jam;
char sampah[1000];
int main() {
    gets(sampah);
    scanf("%d%d%d", &V, &E, &jam);
    R(i,0,E) {
        int va, vi;
        scanf("%d%d", &va, &vi);
        va--; vi--;
        adj[va].push_back(PII(vi,1));
        adj[vi].push_back(PII(va,1));
    }
    vector<int> dist(V+2, INF);
    q.push(PII(0,0));
    dist[0] = 0;
    while(!q.empty()) {
        int jar = q.top().first, u = q.top().second; q.pop();
        if(dist[u] == jar) {
            int len = adj[u].size();
            R(i,0,len) {
                int v = adj[u][i].first, w = adj[u][i].second;
                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    q.push(PII(dist[v], v));
                }
            }
        }
    }
    for(int i=0; i<V; i++) {
        if(dist[i] != INF and dist[i] <= jam) printf("%d\n", i+1);
    }
    return 0;
}
