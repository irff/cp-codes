#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef pair<int,int> PII;

const int INF = 2000111222;
int V, E, HP, start, finish;
vector<PII> adj[600];
priority_queue< greater<PII>(), vector<PII> > q;
int main() {
    scanf("%d%d", &E, &V);
    R(i,0,E) {
        int va, vi, c, w = 0;
        scanf("%d%d%d", &va, &vi, &c);
        va--; vi--;
        
        if(c<=3) w = (int)((c*c)/2);
        else w = (int)( (c*c)/2 - 3*c + 9);
        
        adj[va].push_back(PII(vi,w));
        adj[vi].push_back(PII(va,w));
    }
    scanf("%d%d%d", &HP, &start, &finish);
    start--; finish--;
    vector<int> dist(V+2,INF);
    dist[start] = 0;
    q.push(PII(0,start));
    while(!q.empty()) {
        int d = q.top().first, u = q.top().second; q.pop();
        if(dist[u] == d) {
            int len = adj[u].size();
            R(i,0,len) {
                int vert = adj[u][i].first, w = adj[u][i].second;
                if(dist[vert] > dist[u] + w) {
                    dist[vert] = dist[u] + w;
                    q.push(PII(dist[vert], vert));
                }
            }
        }
    }
    //printf("%d %d\n", HP, dist[finish]);
    if(HP > dist[finish]) {
        printf("%d\n", HP-dist[finish]);
    } else {
        printf("Resurrecting...\n");
    }
    return 0;
}
