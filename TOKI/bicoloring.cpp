#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef vector<int> VI;

int V, E;
VI adj[250];
bool color[250];
bool vis[250];

void dfs(int a) {
    vis[a] = 1;
    int len = adj[a].size();
    R(i,0,len) {
        if(!vis[adj[a][i]]) {
            color[adj[a][i]] = 1-color[a];
            dfs(adj[a][i]);
        }
    }
}

int main() {
    while( scanf("%d", &V), V) {
        memset(adj, 0, sizeof adj);
        memset(vis, 0, sizeof vis);
        memset(color, 0, sizeof color);
        scanf("%d", &E);
        R(i,0,E) {
            int a,b; scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        color[0] = 1;
        dfs(0);
        bool bicolorable = 1;
        R(i,0,V) {
            int len = adj[i].size();
            R(j,0,len) {
                if(color[i]==color[adj[i][j]]) {
                    bicolorable = 0;
                    break;
                }
            }
            if(!bicolorable) break;
        }
        if(bicolorable) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }
    return 0;
}
