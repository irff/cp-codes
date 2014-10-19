#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=itn(_a);i>=int(_b);i--)

typedef pair<int,int> PII;
typedef vector<int> VI;

VI adj[31000];
bool visited[31000];

int teskes, V, E,maks=0;

void dfs(int x) {
    if(!visited[x]) {
        visited[x] = 1;
        maks++;
        for(VI::iterator it=adj[x].begin(); it!=adj[x].end(); it++) {
            if(!visited[*it]) dfs(*it);
        }
    }
}

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        memset(adj, 0, sizeof adj);
        memset(visited, 0, sizeof visited);
        int ans = -2000111222;
        scanf("%d%d", &V, &E);
        R(i,0,E) {
            int a, b; scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=1; i<=V; i++) {
            maks = 0;
            if(!visited[i]) {
                dfs(i);
                ans = max(ans, maks);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
